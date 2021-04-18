#include "EPCH.h"
#include "GL_Shader.h"

#include "Entropy/Tools/Log.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

Entropy::Graphics::GL_Shader::GL_Shader(const char* vertexShaderPath, const char* fragmentShaderPath, const char* geometaryShaderPath)
{
	// Compile Shaders
	std::vector<unsigned int> compilations;
	compilations.push_back(Compile(vertexShaderPath, GL_VERTEX_SHADER));
	compilations.push_back(Compile(fragmentShaderPath, GL_FRAGMENT_SHADER));
	if (geometaryShaderPath != nullptr)
		compilations.push_back(Compile(geometaryShaderPath, GL_GEOMETRY_SHADER));

	// Construct Program
	_ID = glCreateProgram();
	for (unsigned int i = 0; i < compilations.size(); i++)
		glAttachShader(_ID, compilations[i]);
	glLinkProgram(_ID);

	// Check for errors
	int isLinked;
	glGetProgramiv(_ID, GL_LINK_STATUS, &isLinked);
	if (!isLinked)
	{
		int maxLength;
		glGetProgramiv(_ID, GL_INFO_LOG_LENGTH, &maxLength);
		char* errorLog = new char[maxLength];
		glGetProgramInfoLog(_ID, maxLength, &maxLength, errorLog);
		glDeleteShader(_ID);

		std::string errString = "Error linking shader program.\n";
		errString.append(vertexShaderPath);
		errString.append(", ");
		errString.append(fragmentShaderPath);
		if (geometaryShaderPath != nullptr)
		{
			errString.append(", ");
			errString.append(geometaryShaderPath);
		}
		errString.append(".\n");
		errString.append(errorLog);

		Entropy::LOG::Error("SHADER_COMPILER", errString.c_str());
	}

	for (unsigned int i = 0; i < compilations.size(); i++)
		glDeleteShader(compilations[i]);
}

void Entropy::Graphics::GL_Shader::Use() const
{
}

unsigned int Entropy::Graphics::GL_Shader::Compile(const char* path, unsigned int type)
{
	std::string shaderType = "Shader";
	if (type == GL_VERTEX_SHADER)
		shaderType = "Vertex Shader";
	else if (type == GL_GEOMETRY_SHADER)
		shaderType = "Geomerty Shader";
	else if (type == GL_FRAGMENT_SHADER)
		shaderType = "Fragment Shader";

	try {
		// Read Shader Source File
		Entropy::LOG::Message("SHADER_COMPILER", (std::string("Load File: ") + path).c_str());
		std::ifstream inFile(path);
		inFile.exceptions(std::ifstream::failbit || std::ifstream::badbit);
		std::stringstream inStream;
		inStream << inFile.rdbuf();
		inFile.close();
		std::string shaderData = inStream.str();
		const char* shaderSource = shaderData.c_str();

		// Compile Shader
		Entropy::LOG::Header("SHADER_COMPILER", ("Compiling " + shaderType).c_str());
		unsigned int compileID = glCreateShader(type);
		glShaderSource(compileID, 1, &shaderSource, NULL);
		glCompileShader(compileID);

		// Check for Compile Errors
		int isCompiled;
		glGetShaderiv(compileID, GL_COMPILE_STATUS, &isCompiled);
		if (!isCompiled)
		{
			int maxLength;
			glGetShaderiv(compileID, GL_INFO_LOG_LENGTH, &maxLength);
			char* errorLog = new char[maxLength];
			glGetShaderInfoLog(compileID, maxLength, &maxLength, errorLog);
			glDeleteShader(compileID);

			Entropy::LOG::Error("SHADER_COMPILER", ("Error Compiling " + shaderType + ": " + std::string(path) + ", " + errorLog).c_str());
			return 0;
		}
		return compileID;
	}
	catch (std::ifstream::failure e)
	{
		Entropy::LOG::Error("SHADER_COMPILER", (std::string("Shader file, ") + path + ", not succefully read.").c_str());
		return 0;
	}
	
}
