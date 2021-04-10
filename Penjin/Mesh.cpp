#include "Mesh.h"
#include "File.h"
#include <fstream>

namespace Penjin {

	std::string Mesh::GetVertexClassString(Vertex vertex) {
		char buff[300];
		snprintf(buff, sizeof(buff), "Vertex({ %ff, %ff, %ff }, { %ff, %ff }, { %ff, %ff, %ff }, { 1.0f, 1.0f, 1.0f, 1.0f }),\n",
			vertex.x, vertex.y, vertex.z,
			vertex.u, vertex.v,
			vertex.normX, vertex.normY, vertex.normZ);
		std::string buffAsStdStr = buff;
		return buffAsStdStr;
	}


	void Mesh::Export(std::string filename)
	{
		std::ofstream outputFile(filename, std::ios::out | std::ios::binary);
		if (outputFile.fail()) {
			return;
		}
		size_t numVertices = vertices.size();
		size_t numIndices = indices.size();
		outputFile.write((char*)&numVertices, sizeof(size_t));
		outputFile.write((char*)&numIndices, sizeof(size_t));
		for (size_t i = 0; i < vertices.size(); i++)
		{
			outputFile.write((char*)&vertices[i].x, sizeof(float));
			outputFile.write((char*)&vertices[i].y, sizeof(float));
			outputFile.write((char*)&vertices[i].z, sizeof(float));
			outputFile.write((char*)&vertices[i].u, sizeof(float));
			outputFile.write((char*)&vertices[i].v, sizeof(float));
			outputFile.write((char*)&vertices[i].normX, sizeof(float));
			outputFile.write((char*)&vertices[i].normY, sizeof(float));
			outputFile.write((char*)&vertices[i].normZ, sizeof(float));
		}
		for (size_t i = 0; i < indices.size(); i++)
		{
			outputFile.write((char*)&indices[i], sizeof(unsigned int));
		}
		outputFile.close();
	}
	void Mesh::ExportClassFormat(std::string filename)
	{
		std::string expVertex = 
			"Mesh * mesh = new Mesh();\n"
			"Vertex vertices[] = {\n";
		for (size_t i = 0; i < vertices.size(); i++)
		{
			expVertex += "\t" + GetVertexClassString(vertices[i]);
		}
		expVertex +=
			"};\n"
			"int indices[] = {\n\t";
		for (size_t i = 0; i < indices.size(); i++)
		{
			expVertex += std::to_string(indices[i]) + ",";
			if (i % 6 == 5)
				expVertex += "\n\t";
		}
		expVertex +="\n};\n"
		"\n"
		"mesh->vertices = std::vector<Vertex>(vertices, vertices + sizeof vertices / sizeof Vertex);\n"
		"mesh->indices = std::vector<unsigned int>(indices, indices + sizeof indices / sizeof(unsigned int));\n";

		File::Write(filename, expVertex);
	}
}
