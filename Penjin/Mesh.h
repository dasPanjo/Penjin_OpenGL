#pragma once
#include <vector>
#include "Vertex.h"

namespace Penjin {
	class Mesh
	{
		public:
			Mesh(){}
			Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices) :vertices(vertices), indices(indices){}
			std::vector<Vertex> vertices;
			std::vector<unsigned int> indices;
	};
}