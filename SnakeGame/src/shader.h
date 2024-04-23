#ifndef __SHADER_H__
#define __SHADER_H__

#include<fstream>
#include<sstream>
#include<iostream>

bool shader(const char* vertexShaderSource, const char* fragmentShaderSource)
{
	std::fstream file;

	// LOAD VERTEX SHADER
	file.open(vertexShaderSource, std::fstream::in);
	if(!file.is_open())
	{
		std::cerr << "Error opening vertexShaderSource file\n";
		return false;
	}
	std::cout << "VertexShaderSource Opened!\n";
	std::stringstream vertexShaderStream;
	vertexShaderStream << file.rdbuf();
	std::string vertexCode = vertexShaderStream.str();
	file.close();

	// LOAD FRAGMENT SHADER
	file.open(fragmentShaderSource, std::fstream::in);
	if(!file.is_open())
	{	
		std::cerr << "Error opening fragmentShaderSource file\n";
		return false;
	}
	std::cout << "FragmentShaderSource Opened!\n";
	std::stringstream fragmentShaderStream;
	fragmentShaderStream << file.rdbuf();
	std::string fragmentCode = fragmentShaderStream.str();
	file.close();
	
	return true;
}

#endif