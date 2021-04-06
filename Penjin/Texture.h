#pragma once
#include <string>

namespace Penjin
{
	class Texture
	{
	public:
		Texture();
		Texture(const char* filename);

		void Load(const char* filename);
		void Bind(unsigned int slot);
	private:
		std::string		m_filename;
		int	m_width;
		int	m_height;
		int m_bitsPerPixel;
		unsigned int	m_glHandle;
	};
}

