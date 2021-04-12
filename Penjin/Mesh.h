#pragma once
#include <vector>
#include "Vertex.h"

namespace Penjin {
	class Mesh
	{
	public:
		Mesh() {}
		Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices) :vertices(vertices), indices(indices) {}
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;

		void Export(std::string filename);
		void ExportClassFormat(std::string filename);

		std::string GetName() const { return name; }
		void SetName(std::string name) { this->name = name; }
	private:
		std::string name;
		std::string GetVertexClassString(Vertex v);
	};
}