#pragma once
#include <vector>
#include "Vertex.h"

namespace Penjin {
	class Mesh
	{
		public:
			std::vector<Vertex> vertices;
			std::vector<unsigned int> indices;
	};
}

