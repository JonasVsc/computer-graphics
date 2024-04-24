#ifndef __SHADER_H__
#define __SHADER_H__

#include<GL\glew.h>
#include<GLFW\glfw3.h>

#include<fstream>
#include<sstream>
#include<iostream>


class shader
{
public:
	shader(const char *p_vertex_file_path, const char *p_fragment_file_path);

	static const char* read_file(const char *p_shader_file_path);
    static void create_program();

	GLuint program;
	GLuint vertex_shader;
	GLuint fragment_shader;
private:
	static void catch_shader_compile_errors(GLuint shader);
	static void catch_program_compile_errors(GLuint program);

};

#endif