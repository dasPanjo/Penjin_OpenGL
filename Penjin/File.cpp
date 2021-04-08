#include "File.h"
#include <fstream>
#include "Log.h"

namespace Penjin {
	bool File::Exists(const char* filename) {
		std::ifstream f(filename);
		return f.good();
	}

	bool File::Write(const char* filename, const char* text, int maxFileSize)
	{
		std::ofstream filestream(filename, std::ios::out);
		if (filestream.fail()) {
			Log::Error("File::Write error: file '" + std::string(filename) + "' not found!", true);
			return false;
		}
		filestream << text;
		filestream.close();
		return true;
	}
	bool File::Append(const char* filename, const char* text, int maxFileSize)
	{
		std::ofstream filestream(filename, std::ios::app);
		if (filestream.fail()) {
			Log::Error("File::Write error: file '" + std::string(filename) + "' not found!", true);
			return false;
		}
		filestream << text;
		filestream.close();
		return true;
	}

	std::string File::Read(const char* filename)
	{
		std::ifstream filestream(filename, std::ios::binary);
		if (filestream.fail()) {
			Log::Error("File::Read error: file '" + std::string(filename) + "' not found!");
			return "";
		}
		std::string contents((std::istreambuf_iterator<char>(filestream)),
			(std::istreambuf_iterator<char>()));
		return contents;
	}

}
