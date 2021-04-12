#include "ObjLoader.h"

#include "File.h"
#include "Log.h"

namespace Penjin {

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

	Mesh* ObjLoader::Load(std::string filename)
	{
		Mesh* mesh = new Mesh();
		std::string data = File::Read(filename);
		strlist lines = Split(data, '\n');

		std::vector<VertexLoad> loaderVertices;
		std::vector<Vector2> uvs;
		std::vector<Vector3> normals;

		for (size_t i = 0; i < lines.size(); i++)
		{
			std::string currentLine = lines[i];
			if (currentLine.find("v ") == 0)
				ProcessVertexLine(currentLine, &loaderVertices);
			else if (currentLine.find("vt ") == 0)
				ProcessVertexTextureLine(currentLine, &uvs);
			else if (currentLine.find("vn ") == 0)
				ProcessVertexNormalLine(currentLine, &normals);
			else if (currentLine.find("f ") == 0)
				ProcessFaceLine(currentLine, mesh, &loaderVertices, uvs, normals);
		}
		std::vector<Vertex> vertices;
		for (size_t i = 0; i < loaderVertices.size(); i++)
		{
			vertices.push_back((Vertex)loaderVertices[i]);
		}
		mesh->vertices = vertices;
		return mesh;
	}
	void ObjLoader::ProcessVertexLine(std::string line, std::vector<VertexLoad>* vertices)
	{
		strlist info = Split(line, ' ');
		if (info.size() >= 4) {
			Vector3 position = Vector3(std::stof(info[1]), std::stof(info[2]), std::stof(info[3]));
			VertexLoad vertex(position, { 0,0 }, { 0,0,0 });
			vertices->push_back(vertex);
		}
	}
	void ObjLoader::ProcessVertexTextureLine(std::string line, std::vector<Vector2>* uvs)
	{
		strlist info = Split(line, ' ');
		if (info.size() >= 3) {
			uvs->push_back(Vector2(std::stof(info[1]), std::stof(info[2])));
		}
	}
	void ObjLoader::ProcessVertexNormalLine(std::string line, std::vector<Vector3>* normals)
	{
		strlist info = Split(line, ' ');
		if (info.size() >= 4) {
			normals->push_back(Vector3(std::stof(info[1]), std::stof(info[2]), std::stof(info[3])));
		}
	}
	void ObjLoader::ProcessFaceLine(std::string line, Mesh* mesh, std::vector<VertexLoad>* vertices, std::vector<Vector2> uvs, std::vector<Vector3> normals)
	{
		strlist info = Split(line, ' ');
		if (info.size() == 4) {
			for (size_t i = 1; i < 4; i++)
			{
				strlist faceInfo = Split(info[i], '/');
				if (faceInfo.size() >= 3) {
					unsigned int vId = std::stoi(faceInfo[0]) - 1;
					unsigned int tId = std::stoi(faceInfo[1]) - 1;
					unsigned int nId = std::stoi(faceInfo[2]) - 1;
					VertexLoad vertex = vertices->at(vId);

					if (vertex.uvId >= 0)
					{
						if (vertex.uvId != tId || vertex.normId != nId)
						{
							bool found = false;
							for (size_t j = 0; j < vertices->size(); j++)
							{
								VertexLoad testVert = vertices->at(j);
								if (testVert.x == vertex.x && testVert.y == vertex.y && testVert.z == vertex.z &&
									testVert.uvId >= 0 && testVert.uvId == tId &&
									testVert.normId >= 0 && testVert.normId == nId)
								{
									found = true;
									vId = j;
									vertex = testVert;
								}
							}
							if (!found)
							{
								vId = vertices->size();
								Vector3 position = Vector3(vertex.x, vertex.y, vertex.z);
								vertex = VertexLoad(position, { 0,0 }, { 0,0,0 });
								vertices->push_back(vertex);
							}
						}
					}

					vertex.u = uvs[tId].x;
					vertex.v = uvs[tId].y;
					vertex.uvId = tId;

					vertex.normX = normals[nId].x;
					vertex.normY = normals[nId].y;
					vertex.normZ = normals[nId].z;
					vertex.normId = nId;

					vertices->at(vId) = vertex;
					mesh->indices.push_back(vId);
				}
			}
		}
	}
}
