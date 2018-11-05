#include "Shader.h"

using namespace std;
void Shader::createShader()
{
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	
	vShaderFile.open("VertexShader.vs");
	fShaderFile.open("FragmentShader.fs");
	std::stringstream vShaderStream, fShaderStream;
	// read file's buffer contents into streams
	vShaderStream << vShaderFile.rdbuf();
	fShaderStream << fShaderFile.rdbuf();
	// close file handlers
	vShaderFile.close();
	fShaderFile.close();
	// convert stream into string
	vertexCode = vShaderStream.str();
	fragmentCode = fShaderStream.str();

	const char* vShaderCode = vertexCode.c_str();
	const char * fShaderCode = fragmentCode.c_str();

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderCode, NULL);
	glCompileShader(vertexShader);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
	glCompileShader(fragmentShader);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, fragmentShader);
	glAttachShader(shaderProgram, vertexShader);
	glLinkProgram(shaderProgram);

	shaderChecker();
}

void Shader::sendUniform(const GLchar * name, glm::vec3 data)
{
	GLint light = glGetUniformLocation(shaderProgram, name);
	glUseProgram(shaderProgram);
	glProgramUniform3f(shaderProgram, light, data.x, data.y, data.z); // aktualizace dat
	glEnable(GL_DEPTH_TEST);
}

void Shader::sendUniform(const GLchar *name, glm::vec4 data) {
	GLint uniformID = glGetUniformLocation(this->shaderProgram, name);
	if (uniformID >= 0) {
		glUniform4f(uniformID, data.x, data.y, data.z, data.w);
	}
	else {
		printf("uniform error? vec4");
	}
}

void Shader::sendUniform(const GLchar *name, glm::mat4 data) {
	GLint uniformID = glGetUniformLocation(this->shaderProgram, name);
	if (uniformID >= 0) {
		glUniformMatrix4fv(uniformID, 1, GL_FALSE, glm::value_ptr(data));
	}
	else {
		printf("uniform error mat4?");
	}
}

//setting lightning intensity and color

void Shader::rotate(float rotation)
{
	//Render
	M = glm::translate(M, translate);
	M = glm::rotate(M, rotation, glm::vec3(0.0f, 0.0f, 1.0f));		//roration + direction
	//M = glm::translate(M, glm::vec3(0.0f, +10.0f, 0.0f));
	GLint modelMatrixID = glGetUniformLocation(shaderProgram, "modelMatrix"); //nactu identifikaci z shaderu
	glUseProgram(shaderProgram);
	glUniformMatrix4fv(modelMatrixID, 1, GL_FALSE, glm::value_ptr(M)); //do modelMatrix v shaderu poslu matici M								
																	   //location, count, transpose, *valu
	M = glm::translate(M, -translate);
	
}

void Shader::setLampShader() {
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vLampShaderFile;
	std::ifstream fLampShaderFile;

	vLampShaderFile.open("LampVertexShader.vs");
	fLampShaderFile.open("LampFragmentShader.fs");
	std::stringstream vLampShaderStream, fLampShaderStream;
	// read file's buffer contents into streams
	vLampShaderStream << vLampShaderFile.rdbuf();
	fLampShaderStream << fLampShaderFile.rdbuf();
	// close file handlers
	vLampShaderFile.close();
	fLampShaderFile.close();
	// convert stream into string
	vertexCode = vLampShaderStream.str();
	fragmentCode = fLampShaderStream.str();

	const char* vLampShaderCode = vertexCode.c_str();
	const char * fLampShaderCode = fragmentCode.c_str();

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vLampShaderCode, NULL);
	glCompileShader(vertexShader);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fLampShaderCode, NULL);
	glCompileShader(fragmentShader);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, fragmentShader);
	glAttachShader(shaderProgram, vertexShader);
	glLinkProgram(shaderProgram);

	shaderChecker();
}

void Shader::setTranslate(glm::vec3 translate) {
	this->translate = translate;
}

void Shader::setM(glm::mat4 M) {
	this->M = M;
}

GLuint Shader::getProgram() {
	return shaderProgram;
}

void Shader::shaderChecker() {
	GLint status;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}
}

Shader::Shader()
{
}

Shader::~Shader()
{
}


