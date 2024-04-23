#ifndef __SHADER_H__
#define __SHADER_H__

#include<fstream>
#include<sstream>
#include<iostream>

#include<GL\glew.h>
#include<GLFW\glfw3.h>


class shader
{
public:
	shader(const char *p_vertex_file_path, const char *p_fragment_file_path);

	static const char* read_file(const char *p_shader_file_path);
    static void create_shader(const char *p_shader_code, GLenum shaderType);

	GLuint program;
private:
	static bool catch_compile_errors(GLuint shader);

};

#endif