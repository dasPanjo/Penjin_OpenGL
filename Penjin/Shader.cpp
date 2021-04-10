#include "Shader.h"
#include "File.h"
#include "Log.h"

namespace Penjin {
	Shader* Shader::unlitShader = nullptr;
	Shader* Shader::litShader = nullptr;

	Shader::Shader()
	{
		CreateShader(Shader::GetVertDefaultLit(), Shader::GetFragDefaultLit());
	}
	Shader::Shader(const char* vertexShaderFilename, const char* fragmentShaderFilename)
	{
		LoadShader(vertexShaderFilename, fragmentShaderFilename);
	}

	Shader::~Shader()
	{
		glDeleteProgram(shaderID);
	}

	void Shader::Bind()
	{
		glUseProgram(shaderID);
	}

	void Shader::Unbind()
	{
		glUseProgram(0);
	}

	void Shader::LoadShader(const char* vertexShaderFilename, const char* fragmentShaderFilename) {
		shaderID = CreateShader(Parse(vertexShaderFilename), Parse(fragmentShaderFilename));
		Log::Message("Loaded Shader " + std::string(vertexShaderFilename));
	}


	void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
	{
		glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
	}

	void Shader::SetUniform4f(const std::string& name, glm::vec4 vec)
	{
		glUniform4f(GetUniformLocation(name), vec.x, vec.y, vec.z, vec.w);
	}

	void Shader::SetUniform3f(const std::string& name, float v0, float v1, float v2)
	{
		glUniform3f(GetUniformLocation(name), v0, v1, v2);
	}

	void Shader::SetUniform3f(const std::string& name, glm::vec3 vec)
	{
		glUniform3f(GetUniformLocation(name), vec.x, vec.y, vec.z);
	}

	void Shader::SetUniform1i(const std::string& name, int value)
	{
		glUniform1i(GetUniformLocation(name), value);
	}

	void Shader::SetUniform1f(const std::string& name, float value)
	{
		glUniform1f(GetUniformLocation(name), value);
	}

	void Shader::SetUniformMat4f(const std::string& name, const glm::mat4 matrix)
	{
		//parameters: location, count, needs to be transposed, reference to float array ( since we are using a matrix we reference the column 0 row 0)
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
	}

	void Shader::SetUniformMat3f(const std::string& name, const glm::mat3 matrix)
	{
		//parameters: location, count, needs to be transposed, reference to float array ( since we are using a matrix we reference the column 0 row 0)
		glUniformMatrix3fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
	}

	void Shader::SetUniformMat4fArray(const std::string& name, int count, const float* begin)
	{
		//parameters: location, count, needs to be transposed, reference to float array ( since we are using a matrix we reference the column 0 row 0)
		glUniformMatrix4fv(GetUniformLocation(name), count, GL_FALSE, begin);
	}

		
	int Shader::GetUniformLocation(const std::string& name)
	{
		/*looks for current uniform in cache. If its already there, returns the uniform location int. This means we dont have to do the gl call every frame saving resources*/
		if (uniformLocationCache.find(name) != uniformLocationCache.end())
		{
			return uniformLocationCache[name];
		}
		int location = glGetUniformLocation(shaderID, name.c_str());
		if (location == -1)
		{
			Log::Error("Shader error: Uniform '" + name + "' doesnt exist.");
		}
		uniformLocationCache[name] = location;

		return location;
	}

	GLuint Shader::Compile(std::string shaderSource, GLenum type)
	{
		GLuint id = glCreateShader(type);
		const char* src = shaderSource.c_str();
		glShaderSource(id, 1, &src, 0);
		glCompileShader(id);

		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		if (!result)
		{
			int length = 0;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = new char[length];
			glGetShaderInfoLog(id, length, &length, message);

			std::cout << "Shader compilation error: " << message << std::endl;
			delete[] message;
			return 0;
		}
		return id;
	}

	std::string Shader::Parse(const char* filename)
	{
		/*
		FILE* file;
		file = fopen(filename, "rb");
		if (file == nullptr) {
			std::cerr << "File " << filename << " not found!" << std::endl;
			return 0;
		}
		std::string contents;
		fseek(file, 0, SEEK_END);
		size_t filesize = ftell(file);
		rewind(file);
		contents.resize(filesize);
		fread(&contents[0], 1, filesize, file);
		fclose(file);
		*/

		//std::ifstream filestream(filename, std::ios::binary);
		//if (filestream.fail()) {
		//	std::cerr << "Shader-file \"" << filename << "\" not found!" << std::endl;
		//	return "";
		//}
		//std::string contents((std::istreambuf_iterator<char>(filestream)),
		//	(std::istreambuf_iterator<char>()));

		return File::Read(filename);
	}

	GLuint Shader::CreateShader(std::string vertexShaderSource, std::string fragmentShaderSource)
	{
		GLuint program = glCreateProgram();
		GLuint vert = Compile(vertexShaderSource, GL_VERTEX_SHADER);
		GLuint frag = Compile(fragmentShaderSource, GL_FRAGMENT_SHADER);

		glAttachShader(program, vert);
		glAttachShader(program, frag);
		glLinkProgram(program);

#ifdef _RELEASE
		glDetachShader(program, vert);
		glDetachShader(program, frag);

		glDeleteShader(vert);
		glDeleteShader(frag);
#endif


		shaderID = program;
		uniformLocationCache.clear();
		return program;
	}


	Shader* Shader::GetUnlitShader()
	{
		if (unlitShader == nullptr)
		{
			unlitShader = new Shader();
			unlitShader->CreateShader(GetVertDefaultUnlit(), GetFragDefaultUnlit());
		}
		return unlitShader;
	}

	Shader* Shader::GetLitShader()
	{
		if (unlitShader == nullptr)
		{
			unlitShader = new Shader();
			unlitShader->CreateShader(GetVertDefaultLit(), GetFragDefaultLit());
		}
		return unlitShader;
	}

	std::string Shader::GetVertDefaultUnlit()
	{
		return
			"#version 330 core\n"
			""
			"layout(location = 0) in vec3 a_position;"
			"layout(location = 1) in vec2 a_texUV;"
			"layout(location = 2) in vec3 a_normal;"
			"layout(location = 3) in vec4 a_color;"
			""
			"uniform mat4 u_projectionMatrix;"
			"uniform mat4 u_viewMatrix;"
			"uniform mat4 u_modelMatrix;"
			"uniform vec4 u_baseColor;"
			""
			"out vec2 v_texUV;"
			"out vec4 v_color;"
			""
			"void main() {"
			"	gl_Position = u_projectionMatrix * u_viewMatrix * u_modelMatrix * vec4(a_position, 1);"
			"	v_texUV = a_texUV;"
			"	v_color = a_color * u_baseColor;"
			"}";
	}

	std::string Shader::GetFragDefaultUnlit()
	{
		return
			"#version 330 core\n"
			""
			"in vec2 v_texUV;"
			"in vec4 v_color;"
			""
			"uniform sampler2D u_texture;"
			""
			"layout(location = 0) out vec4 f_color;"
			""
			"void main() {"
			"	vec4 texColor = texture(u_texture, v_texUV);"
			"	f_color = v_color * texColor;"
			"}";
	}

	std::string Shader::GetVertDefaultLit()
	{
		return
			"#version 330 core\n"
			""
			"layout(location = 0) in vec3 a_position;"
			"layout(location = 1) in vec2 a_texUV;"
			"layout(location = 2) in vec3 a_normal;"
			"layout(location = 3) in vec4 a_color;"
			""
			"uniform mat4 u_projectionMatrix;"
			"uniform mat4 u_viewMatrix;"
			"uniform mat4 u_modelMatrix;"
			"uniform mat3 u_normalMatrix;"
			"uniform vec4 u_baseColor;"
			""
			"out vec2 v_texUV;"
			"out vec4 v_color;"
			"out vec3 normal;"
			"out vec4 eye;"
			""
			"void main() {"
			"	gl_Position = u_projectionMatrix * u_viewMatrix * u_modelMatrix * vec4(a_position, 1);"
			"	v_texUV = a_texUV;"
			"	v_color = a_color * u_baseColor;"
			""
			"	normal = normalize(u_normalMatrix * a_normal);"
			"	eye = -(u_projectionMatrix * u_viewMatrix * u_modelMatrix * vec4(a_position, 1));"
			"}";
	}

	std::string Shader::GetFragDefaultLit()
	{
		return
			"#version 330 core\n"
			""
			"in vec2 v_texUV;"
			"in vec4 v_color;"
			"in vec3 normal;"
			"in vec4 eye;"
			""
			"uniform sampler2D u_texture;"
			"uniform vec3 u_directionalLightDirection;"
			""
			"layout(location = 0) out vec4 f_color;"
			""
			"void main() {"
			"	vec4 texColor = texture(u_texture, v_texUV);"
			""
			"	vec4 spec = vec4(0.0);"
			""
			"	vec3 n = normalize(normal);"
			"	vec3 e = normalize(vec3(eye));"
			""
			"	vec3 direction = normalize(u_directionalLightDirection);"
			"	float intensity = max(dot(n, direction)*0.8+0.2, 0.2);"
			"	f_color = v_color * texColor * intensity;"
			"}";
	}
}
