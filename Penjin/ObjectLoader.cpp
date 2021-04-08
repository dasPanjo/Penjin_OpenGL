#include "ObjectLoader.h"
#include "File.h"
#include "Log.h"

namespace Penjin {

#define strlist std::vector<std::string>

	//splits given string into vector of sub strings based on positions of delimeter (does not preserve delimiter characters)
	static const strlist Split(const std::string& src, const char& delimeter)
	{
		std::string buffer = "";
		strlist result{};

		for (int i = 0; i < src.size(); i++)
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

	Mesh* ObjectLoader::LoadObjModel(const char* filename)
	{
		Mesh* mesh = new Mesh();
		std::string data = File::Read(filename);
		strlist lines = Split(data, '\n');

		std::vector<Vertex> vertices;
		std::vector<Vector2> uvs;
		std::vector<Vector3> normals;

		for (size_t i = 0; i < lines.size(); i++)
		{
			std::string currentLine = lines[i];
			if (currentLine.find("v ") == 0) 
				ProcessVertexLine(currentLine, &vertices);
			else if (currentLine.find("vt ") == 0) 
				ProcessVertexTextureLine(currentLine, &uvs);
			else if (currentLine.find("vn ") == 0) 
				ProcessVertexNormalLine(currentLine, &normals);
			else if (currentLine.find("f ") == 0) 
				ProcessFaceLine(currentLine, mesh, &vertices, uvs, normals);
		}
		mesh->vertices = vertices;
		return mesh;
	}
	void ObjectLoader::ProcessVertexLine(std::string line, std::vector<Vertex>* vertices)
	{
		strlist info = Split(line, ' ');
		if (info.size() >= 4) {
			Vector3 position = Vector3(std::stof(info[1]), std::stof(info[2]), std::stof(info[3]));
			Vertex vertex(position, { 0,0 }, { 0,0,0 }, { 1,1,1,1 });
			vertices->push_back(vertex);
		}
	}
	void ObjectLoader::ProcessVertexTextureLine(std::string line, std::vector<Vector2>* uvs)
	{
		strlist info = Split(line, ' ');
		if (info.size() >= 3) {
			uvs->push_back(Vector3(std::stof(info[1]), std::stof(info[2])));
		}
	}
	void ObjectLoader::ProcessVertexNormalLine(std::string line, std::vector<Vector3>* normals)
	{
		strlist info = Split(line, ' ');
		if (info.size() >= 4) {
			normals->push_back(Vector3(std::stof(info[1]), std::stof(info[2]), std::stof(info[3])));
		}
	}
	void ObjectLoader::ProcessFaceLine(std::string line, Mesh* mesh, std::vector<Vertex>* vertices, std::vector<Vector2> uvs, std::vector<Vector3> normals)
	{
		strlist info = Split(line, ' ');
		if (info.size() >= 4) {
			for (size_t i = 1; i < 4; i++)
			{
				strlist faceInfo = Split(info[i], '/');
				if (faceInfo.size() >= 3) {
					unsigned int vId = std::stoi(faceInfo[0]) - 1;
					unsigned int tId = std::stoi(faceInfo[1]) - 1;
					unsigned int nId = std::stoi(faceInfo[2]) - 1;
					Vertex v = vertices->at(vId);
					v.u = uvs[tId].x;
					v.v = uvs[tId].y;
					v.normX = normals[nId].x;
					v.normY = normals[nId].y;
					v.normZ = normals[nId].z;
					vertices->at(vId) = v;
					mesh->indices.push_back(vId);
				}
			}
		}
	}
}
