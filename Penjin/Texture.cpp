#include "Texture.h"
#include <GL/glew.h>
#include "stb_image.h"
#include "Log.h"

namespace Penjin {
	Texture::Texture()
		:m_filename("none"),
		m_width(0),
		m_height(0),
		m_bitsPerPixel(0),
		m_glHandle(0)
	{
	}
	Texture::Texture(const char* filename)
		:Texture()
	{
		this->Load(filename);
	}
	void Texture::Load(const char* filename)
	{
		if (m_glHandle != 0) {
			glDeleteTextures(1, &m_glHandle);
			m_glHandle = 0;
			m_width = 0;
			m_height = 0;
			m_filename = "none";
		}

		m_filename = std::string(filename);

		auto textureBuffer = stbi_load(filename, &m_width, &m_height, &m_bitsPerPixel, 4);
		if (textureBuffer == nullptr) {
			Log::Error("Texture '"+ std::string(filename) +"' not found!");
			return;
		}

		glGenTextures(1, &m_glHandle);
		glBindTexture(GL_TEXTURE_2D, m_glHandle);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureBuffer);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);

		if (textureBuffer) {
			stbi_image_free(textureBuffer);
		}
	}
	void Texture::Bind(unsigned int slot)
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, m_glHandle);
	}
}