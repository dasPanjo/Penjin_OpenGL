#pragma once
#include <string>

namespace Penjin {
	class File
	{
	public:
		static bool Exists(const char* filename);
		static bool Exists(std::string filename) { return Exists(filename.c_str()); }

		static bool Write(const char* filename, const char* text, int maxFileSize = -1);
		static bool Write(const char* filename, std::string text, int maxFileSize = -1) { return Write(filename, text.c_str(), maxFileSize); }
		static bool Write(std::string filename, std::string text, int maxFileSize = -1) { return Write(filename.c_str(), text.c_str(), maxFileSize); }
		static bool Write(std::string filename, const char* text, int maxFileSize = -1) { return Write(filename.c_str(), text, maxFileSize); }

		static bool Append(const char* filename, const char* text, int maxFileSize = -1);
		static bool Append(const char* filename, std::string text, int maxFileSize = -1) { return Append(filename, text.c_str(), maxFileSize); }
		static bool Append(std::string filename, std::string text, int maxFileSize = -1) { return Append(filename.c_str(), text.c_str(), maxFileSize); }
		static bool Append(std::string filename, const char* text, int maxFileSize = -1) { return Append(filename.c_str(), text, maxFileSize); }

		static std::string Read(const char* filename);
		static std::string Read(std::string filename) { Read(filename.c_str()); }
	};
}

