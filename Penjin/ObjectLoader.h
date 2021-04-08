#pragma once
#include "Mesh.h"

namespace Penjin {
	class ObjectLoader
	{
	public:
		static Mesh* LoadObjModel(const char* filename);
	private:
		static void ProcessVertexLine(std::string line, std::vector<Vertex>* vertices);
		static void ProcessVertexTextureLine(std::string line, std::vector<Vector2>* uvs);
		static void ProcessVertexNormalLine(std::string line, std::vector<Vector3>* normals);
		static void ProcessFaceLine(std::string line, Mesh* mesh, std::vector<Vertex>* vertices, std::vector<Vector2> uvs, std::vector<Vector3> normals);
	};
}

