#include"shader.h"


shader::shader(const char *p_vertex_file_path, const char *p_fragment_file_path)
{
	const char* p_vertex_shader = read_file(p_vertex_file_path);
	const char* p_fragment_shader = read_file(p_fragment_file_path);

	// create shader program then compile
	create_shader(p_vertex_shader, GL_VERTEX_SHADER);
	create_shader(p_fragment_shader, GL_FRAGMENT_SHADER);

	// create program
}

const char* shader::read_file(const char *p_shader_file_path)
{
	// open file
	// ---------
	std::fstream file {};
	file.open(p_shader_file_path, std::fstream::in);

	// check error
	// -----------
	if(!file.is_open())
	{
		std::cerr << "Error opening file\n";
	}

	// read file
	// ---------
	std::stringstream file_stream;
	file_stream << file.rdbuf();

	// convert to str
	// ----------------
	std::string file_str = file_stream.str();

	file.close();

	// convert to c_str
	// ---------------- 
	const char* file_code = file_str.c_str();
	return file_code;
}

void shader::create_shader(const char *p_shader_code, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);
	glCompileShader(shader);

	// catch compile errors
	if(!catch_compile_errors(shader))
	{
		std::string type {"UNDEFINED"};
		if(shaderType == GL_VERTEX_SHADER)
			type = "GL_VERTEX_SHADER";
		if(shaderType == GL_VERTEX_SHADER)
			type = "GL_FRAGMENT_SHADER";

		std::cerr << "ERROR COMPILATION " << type;
	}
}

bool shader::catch_compile_errors(GLuint shader)
{
	int shader_compiled;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &shader_compiled);
	if(shader_compiled != GL_TRUE)
	{
		GLsizei log_length = 0;
	    GLchar message[1024];
	    glGetShaderInfoLog(shader, 1024, &log_length, message);
	    std::cerr << message << '\n';
	    return false;
	}
	return true;
}



// void shader::read_file(const char *p_file_path)
// {
// 	std::fstream file;

// 	file.open(p_file_path, std::fstream::in);
// 	if(!file.is_open())
// 	{
// 		std::cerr << "Error opening file\n";
// 	}
// 	std::stringstream fileStream;
// 	fileStream << file.rdbuf();

// 	// convert to str then c_str
// 	// =========================
// 	std::string file_code_str = fileStream.str();
// 	const char* file_code_c_str = file_code_str.c_str();

// 	file.close();
// }

// void shader::compile_shader(const char *p_shader_code)
// {
// 	GLuint shader = glCreateShader(GL_VERTEX_SHADER);
// }

// void shader::catch_compile_errors()
// {
// 	int vertex_compiled;
// 	glGetShaderiv(p_shader_code, GL_COMPILE_STATUS, &vertex_compiled);
// 	if(vertex_compiled != GL_TRUE)
// 	{
// 		GLsizei log_length = 0;
// 	    GLchar message[1024];
// 	    glGetShaderInfoLog(vertexShader, 1024, &log_length, message);
// 	    std::cerr << message << '\n';
// 	    return false;
// 	}
// }