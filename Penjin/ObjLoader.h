#pragma once
#include "Mesh.h"
namespace Penjin
{
	class ObjLoader
	{
	public:
		static Mesh* Load(std::string filename);
	private:
		class VertexLoad : public Vertex {
		public:
			VertexLoad(Vector3 position, Vector2 uv, Vector3 normal) :
				Vertex(position, uv, normal, { 1,1,1,1 }) {}
			int uvId = -1;
			int normId = -1;
		};
		static void ProcessVertexLine(std::string line, std::vector<VertexLoad>* vertices);
		static void ProcessVertexTextureLine(std::string line, std::vector<Vector2>* uvs);
		static void ProcessVertexNormalLine(std::string line, std::vector<Vector3>* normals);
		static void ProcessFaceLine(std::string line, Mesh* mesh, std::vector<VertexLoad>* vertices, std::vector<Vector2> uvs, std::vector<Vector3> normals);

	};
}

