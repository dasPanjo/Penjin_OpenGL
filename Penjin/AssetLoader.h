#pragma once
#include "Mesh.h"

namespace Penjin {
	class AssetLoader
	{
	public:
		static Mesh* LoadModel(std::string filename);
		static Mesh* LoadObjModel(std::string filename);
		static Mesh* LoadModelAsset(std::string filename);
	private:
		static Penjin::Mesh* LoadModelWithExtension(std::string filename, std::string extension);
		static Penjin::Mesh* LoadModelWithoutExtension(std::string& filename);

	};
}

