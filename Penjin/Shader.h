#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <GL/glew.h>
#include "glm/glm.hpp"

namespace Penjin {

	class Shader
	{
	public:
		Shader();
		Shader(const char* vertexShaderFilename, const char* fragmentShaderFilename);
		virtual ~Shader();

		void Bind();
		void Unbind();

		void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
		void SetUniform4f(const std::string& name, glm::vec4 vec);
		void SetUniform3f(const std::string& name, float v0, float v1, float v2);
		void SetUniform3f(const std::string& name, glm::vec3 vec);
		void SetUniform1i(const std::string& name, int value);
		void SetUniform1f(const std::string& name, float value);
		void SetUniformMat4f(const std::string& name, const glm::mat4 matrix);
		void SetUniformMat3f(const std::string& name, const glm::mat3 matrix);
		void SetUniformMat4fArray(const std::string& name, int count, const float* begin);
		int GetUniformLocation(const std::string& name);

		inline GLuint GetShaderID() { return shaderID; }

	private:
		GLuint Compile(std::string shaderSource, GLenum type);
		std::string Parse(const char* filename);
		GLuint CreateShader(std::string vertexShaderSource, std::string fragmentShaderSource);

		GLuint shaderID;  

		/*unordered map for uniforms. Previously called uniforms can be found in this map, which is faster than repeatidly searching large shader source code for a single uniform.*/
		std::unordered_map<std::string, int> uniformLocationCache;
	};
}

