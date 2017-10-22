//#include "GLSL_Program.h"
//#include "Errors.h"
//#include <fstream>
//#include <cstdio>
//#include <vector>
//
//GLSL_Program::GLSL_Program() : ID(0), vertID(0), fragID(0), numAttributes(0)
//{
//}
//
//
//GLSL_Program::~GLSL_Program()
//{ 
//}
//
//void GLSL_Program::linkShaders()
//{
//	//Vertex and fragment shaders are successfully compiled.
//	//Now time to link them together into a program.
//	//Get a program object.
//	ID = glCreateProgram();
//
//	//Attach our shaders to our program
//	glAttachShader(ID, vertID);
//	glAttachShader(ID, fragID);
//
//	//Link our program
//	glLinkProgram(ID);
//
//	//Note the different functions here: glGetProgram* instead of glGetShader*.
//	GLint isLinked = 0;
//	glGetProgramiv(ID, GL_LINK_STATUS, (int *)&isLinked);
//	if (isLinked == GL_FALSE)
//	{
//		GLint maxLength = 0;
//		glGetProgramiv(ID, GL_INFO_LOG_LENGTH, &maxLength);
//
//		//The maxLength includes the NULL character
//		vector<char> errorLog(maxLength);
//		glGetProgramInfoLog(ID, maxLength, &maxLength, &errorLog[0]);
//
//		//We don't need the program anymore.
//		glDeleteProgram(ID);
//		//Don't leak shaders either.
//		glDeleteShader(vertID);
//		glDeleteShader(fragID);
//
//		printf("%s\n", &errorLog[0]);
//		fatal_error("Shaders failed to compile");
//	}
//
//	//Always detach shaders after a successful link.
//	glDetachShader(ID, vertID);
//	glDetachShader(ID, fragID);
//	glDeleteShader(vertID);
//	glDeleteShader(fragID);
//}
//
//void GLSL_Program::addAttribute(const string& attributeName) {
//	
//	glBindAttribLocation(ID, numAttributes++, attributeName.c_str());
//}
//
//
//void GLSL_Program::compileShaders(const string& vertex_shader_file_path, const string& frag_shader_file_path)
//{
//	vertID = glCreateShader(GL_VERTEX_SHADER);	//devuelve un vertex shader que guardaremos en el gLuint vertID
//	if (vertID == 0)
//		fatal_error("Vertex shader failed to be crated.");
//
//	fragID = glCreateShader(GL_FRAGMENT_SHADER);	//devuelve un fragment shader que guardaremos en el gLuint vertID
//	if (fragID == 0)
//		fatal_error("Fragment shader failed to be crated.");
//
//	compileShader(vertex_shader_file_path, vertID);
//	compileShader(frag_shader_file_path, fragID);	
//}
//
//
//void GLSL_Program::compileShader(const string& filePath, GLuint ID) {
//
//	ifstream vertexFile(filePath);
//	if (vertexFile.fail()) {
//		perror(filePath.c_str());
//		fatal_error("failed to open " + filePath);
//	}
//
//	string fileContent = "";	//leer todos los datos del archivo en un solo string
//	string line;
//
//	while (getline(vertexFile, line))
//		fileContent += line + "\n";
//
//	vertexFile.close();
//
//	const char* contentPtr = fileContent.c_str();
//	glShaderSource(ID, 1, &contentPtr, nullptr);
//
//	glCompileShader(ID);
//
//	GLint success = 0;											// gestion de errores al compilar el shader
//	glGetShaderiv(ID, GL_COMPILE_STATUS, &success);
//
//	if (success == GL_FALSE)
//	{
//		GLint maxLength = 0;
//		glGetShaderiv(ID, GL_INFO_LOG_LENGTH, &maxLength);
//
//		// The maxLength includes the NULL character
//		vector<char> errorLog(maxLength);
//		glGetShaderInfoLog(ID, maxLength, &maxLength, &errorLog[0]);
//
//		// Provide the infolog in whatever manor you deem best.
//		// Exit with failure.
//		glDeleteShader(ID); // Don't leak the shader.
//
//		printf("%s\n", &errorLog[0]);
//		fatal_error("Shader " + filePath +" failed to compile");
//	}
//}