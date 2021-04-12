#include "AssetLoader.h"
#include "File.h"
#include "Log.h"
#include "ObjLoader.h"
#include <fstream>

namespace Penjin
{
#define strlist std::vector<std::string>

	//splits given string into vector of sub strings based on positions of delimeter (does not preserve delimiter characters)
	static const strlist Split(const std::string& src, const char& delimeter)
	{
		std::string buffer = "";
		strlist result{};

		for (size_t i = 0; i < src.size(); i++)
		{
			char c = src[i];
			if (c != delimeter)
			{
				buffer += c;
			}
			else if (c == delimeter && buffer != "")
			{
				result.push_back(buffer);
				buffer = "";
			}
		}
		if (buffer != "")
		{
			result.push_back(buffer);
		}

		return result;
	}

	Mesh* AssetLoader::LoadModel(std::string filename)
	{
		Mesh* mesh = nullptr;
		size_t dotPosition = filename.find_last_of(".");
		bool hasFileExtension = (dotPosition < filename.length());
		if (hasFileExtension)
		{
			std::string extension = filename.substr(dotPosition, filename.length() - dotPosition);
			mesh = LoadModelWithExtension(filename, extension);
			if (mesh != nullptr) return mesh;
		}
		mesh = LoadModelWithoutExtension(filename);
		if (mesh != nullptr) return mesh;

		Log::Error("Unable to find asset '" + filename + "'");
		return mesh;
	}

	Mesh* AssetLoader::LoadObjModel(std::string filename)
	{
		Mesh* mesh = ObjLoader::Load(filename);
		if (mesh != nullptr)
		{
			mesh->SetName(filename);
			size_t dotPosition = filename.find_last_of(".");
			std::string fileNoExt = filename.substr(0, dotPosition);
			mesh->Export(fileNoExt + ".pAsset");
			return mesh;
		}
		else {
			Log::Error("[" + std::string(__FUNCTION__) + "]: Unable to load '" + std::string(filename)+"'");
			return nullptr;
		}
	}
	Mesh* AssetLoader::LoadModelAsset(std::string filename)
	{
#ifdef _DEBUG
		Log::Message("LOADING pAsset FILE ----> " + std::string(filename));
#endif
		std::ifstream inputFile(filename, std::ios::in | std::ios::binary);
		if (inputFile.fail()) {
			Log::Error("Unable to read file " + std::string(filename));
			return nullptr;
		}
		size_t numVertices;
		size_t numIndices;
		inputFile.read((char*)&numVertices, sizeof(size_t));
		inputFile.read((char*)&numIndices, sizeof(size_t));
		std::vector<Vertex> vertices;
		for (size_t i = 0; i < numVertices; i++)
		{
			float x, y, z;
			float u, v;
			float normX, normY, normZ;
			inputFile.read((char*)&x, sizeof(float));
			inputFile.read((char*)&y, sizeof(float));
			inputFile.read((char*)&z, sizeof(float));
			inputFile.read((char*)&u, sizeof(float));
			inputFile.read((char*)&v, sizeof(float));
			inputFile.read((char*)&normX, sizeof(float));
			inputFile.read((char*)&normY, sizeof(float));
			inputFile.read((char*)&normZ, sizeof(float));
			vertices.push_back(Vertex({ x,y,z }, { u,v }, { normX, normY, normZ }, { 1,1,1,1 }));
		}
		std::vector<unsigned int> indices;
		for (size_t i = 0; i < numIndices; i++)
		{
			int index;
			inputFile.read((char*)&index, sizeof(unsigned int));
			indices.push_back(index);
		}
		Mesh* mesh = new Mesh();
		mesh->SetName(filename);
		mesh->vertices = vertices;
		mesh->indices = indices;
		return mesh;
	}



	Penjin::Mesh* AssetLoader::LoadModelWithExtension(std::string filename, std::string extension)
	{
		if (extension == "obj") {
			return LoadObjModel(filename);
		}
		else if (extension == "pAsset") {
			return LoadModelAsset(filename);
		}
		Log::Error("Unknown File-extension: '" + std::string(filename) + "'");
		return nullptr;
	}

	Penjin::Mesh* AssetLoader::LoadModelWithoutExtension(std::string& filename)
	{
		Mesh* mesh = nullptr;
		std::string pAssetFile = filename + ".pAsset";
		std::string objFile = filename + ".obj";

		if (File::Exists(pAssetFile))
		{
			if (File::Exists(objFile)) {
				std::string newestFile = File::GetNewestFile(pAssetFile, objFile);
				if (newestFile == objFile)
				{
					Log::Message("Asset '" + pAssetFile + "' reimporting obj");
					mesh = LoadObjModel(objFile);
					if (mesh != nullptr) return mesh;
				}
				else {
					mesh = LoadModelAsset(pAssetFile);
					if (mesh != nullptr) return mesh;
				}
			}
			else {
				mesh = LoadModelAsset(pAssetFile);
				if (mesh != nullptr) return mesh;
			}
		}

		if (File::Exists(objFile))
		{
			Log::Message("Asset '" + pAssetFile + "' reimporting obj");
			mesh = LoadObjModel(objFile);
			if (mesh != nullptr) return mesh;
		}
		return nullptr;
	}

}
