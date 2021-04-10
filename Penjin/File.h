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

		static std::string GetNewestFile(const char* filename, const char* filename2);
		static std::string GetNewestFile(std::string filename, std::string filename2) { return GetNewestFile(filename.c_str(), filename2.c_str()); }

		//static std::string Compress(std::string text);
		//static std::string Decompress(std::string text);

		static std::string Read(const char* filename);
		static std::string Read(std::string filename) { return Read(filename.c_str()); }
	};
}

