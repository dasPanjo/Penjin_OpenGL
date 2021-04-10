#define _CRT_SECURE_NO_WARNINGS
#include "File.h"
#include <fstream>
#include "Log.h"
#include <iostream>
#include <Windows.h>

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

	SYSTEMTIME GetFiletime(const char* filename) {
		HANDLE hFile1;
		FILETIME ftCreate;
		SYSTEMTIME stUTC;
		hFile1 = CreateFile(TEXT(filename), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		if (hFile1 == INVALID_HANDLE_VALUE)
		{
			printf("Could not open file, error %ul\n", GetLastError());
			return SYSTEMTIME();
		}

		if (!GetFileTime(hFile1, NULL, NULL, &ftCreate))
		{
			printf("Something wrong!\n");
			return SYSTEMTIME();
		}
		CloseHandle(hFile1);

		FileTimeToSystemTime(&ftCreate, &stUTC);
		return stUTC;
	}

	std::string File::GetNewestFile(const char* filename, const char* filename2)
	{
		SYSTEMTIME t1 = GetFiletime(filename);
		SYSTEMTIME t2 = GetFiletime(filename2);

		if (t1.wYear > t2.wYear) return filename;
		if (t2.wYear > t1.wYear) return filename2;
		if (t1.wMonth > t2.wMonth) return filename;
		if (t2.wMonth > t1.wMonth) return filename2;
		if (t1.wDay > t2.wDay) return filename;
		if (t2.wDay > t1.wDay) return filename2;

		if (t1.wHour > t2.wHour) return filename;
		if (t2.wHour > t1.wHour) return filename2;
		if (t1.wMinute > t2.wMinute) return filename;
		if (t2.wMinute > t1.wMinute) return filename2;
		if (t1.wSecond > t2.wSecond) return filename;
		if (t2.wSecond > t1.wSecond) return filename2;
		if (t1.wMilliseconds > t2.wMilliseconds) return filename;
		if (t2.wMilliseconds > t1.wMilliseconds) return filename2;

		return filename;
	}

	//std::string File::Compress(std::string text)
	//{
	//	int posInText = 0;
	//	int letterCounter = 0;
	//	char currentLetter = 0x00;
	//	std::string output = "";
	//	while (posInText < text.length()) {
	//		currentLetter = text[posInText];
	//		if (posInText + 1 < text.length() && text[posInText + 1] == currentLetter) {
	//			letterCounter++;
	//		}
	//		else {
	//			if (letterCounter == 1 || letterCounter == 2)
	//			{
	//				for (size_t i = 0; i < letterCounter; i++)
	//				{
	//					output += currentLetter;
	//				}
	//				output += currentLetter;
	//				letterCounter = 0;
	//			}
	//			else if (letterCounter > 1)
	//			{
	//				output += ";" + std::to_string(letterCounter + 1) + "x" + currentLetter;
	//				letterCounter = 0;
	//			}
	//			else {
	//				output += currentLetter;
	//			}
	//		}
	//		posInText++;
	//	}
	//	if (letterCounter == 1 || letterCounter == 2)
	//	{
	//		for (size_t i = 0; i < letterCounter; i++)
	//		{
	//			output += currentLetter;
	//		}
	//		output += currentLetter;
	//		letterCounter = 0;
	//	}
	//	else if (letterCounter > 1)
	//	{
	//		output += ";" + std::to_string(letterCounter + 1) + currentLetter;
	//		letterCounter = 0;
	//	}
	//	return output;
	//}

	//std::string File::Decompress(std::string text)
	//{
	//	int posInText = 0;
	//	std::string output = "";
	//	while (posInText < text.length()) {
	//		char currentLetter = text[posInText];
	//		if (currentLetter != ';')
	//		{
	//			output += currentLetter;
	//		}
	//		else 
	//		{
	//			std::string ammount = text.substr(posInText + 1, text.length() - posInText);
	//			int posX = ammount.find('x');
	//			int size = std::stoi(text.substr(posInText + 1, posX));
	//			posInText += 2+posX;
	//			currentLetter = text[posInText];
	//			for (size_t i = 0; i < size; i++)
	//			{
	//				output += currentLetter;
	//			}
	//		}
	//		posInText++;
	//	}
	//	return output;
	//}

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
