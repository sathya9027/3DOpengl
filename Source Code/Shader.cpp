#include "Common.h"
Shader::Shader() {
	this->programObj = NULL;
	this->vertexAttribute = NULL;
	this->colorAttribute = NULL;
	this->uvAttribute = NULL;
	this->modelAttribute = NULL;
	this->lightAttribute = NULL;
	this->normalAttribute = NULL;
	this->projectionAttribute = NULL;
	this->viewAttribute = NULL;
	this->lightPosAttribute = NULL;
	this->viewPosAttribute = NULL;
}
Shader::~Shader() {

}
void Shader::ShaderInit() {
	//initializing glew after creating window
	glewInit();
	this->programObj = glCreateProgram();
}
string Shader::ReadShaderFile(const char* filename) {
	string code;
	ifstream file(filename);
	if (!file.good()) {
		cout << "Can't read file " << filename << endl;
		terminate();
	}
	else {
		file.seekg(0, ios::end);
		code.resize(file.tellg());
		file.seekg(0, ios::beg);
		file.read(&code[0], code.size());
		file.close();
	}
	return code;
}
void Shader::ProcessShaderFile(const char* filename, GLenum shaderType) {
	//initializing fragment shader
	string shaderCode = this->ReadShaderFile(filename);

	//reading fragment shader
	GLuint shaderObj = glCreateShader(shaderType);
	const char* code = shaderCode.c_str();
	const int size = shaderCode.size();
	glShaderSource(shaderObj, 1, &code, &size);

	//compiling fragment shader
	glCompileShader(shaderObj);
	glAttachShader(this->programObj, shaderObj);
}
void Shader::GetShaderAttributes() {
//	//attrib location
//	this->vertexAttribute = glGetAttribLocation(this->programObj, "_vertices");	
//	this->uvAttribute = glGetAttribLocation(this->programObj, "_uvcoords");	
//	this->colorAttribute = glGetAttribLocation(this->programObj, "_color");
//	this->normalAttribute = glGetAttribLocation(this->programObj, "_vs_normals");
//	//uniform location
//	this->modelAttribute = glGetUniformLocation(this->programObj, "_model");
//	this->viewAttribute = glGetUniformLocation(this->programObj, "_view");
//	this->projectionAttribute = glGetUniformLocation(this->programObj, "_projection");
//	this->lightAttribute = glGetUniformLocation(this->programObj, "_lightColor");
//	this->lightPosAttribute = glGetUniformLocation(this->programObj, "_lightPos");
//	this->viewPosAttribute = glGetUniformLocation(this->programObj, "_viewPos");



	//MVP
	this->modelAttribute = glGetUniformLocation(this->programObj, "_model");
	this->viewAttribute = glGetUniformLocation(this->programObj, "_view");
	this->projectionAttribute = glGetUniformLocation(this->programObj, "_projection");

	//box and light
	this->vertexAttribute = glGetAttribLocation(this->programObj, "_vertices");

	//box
	this->uvAttribute = glGetAttribLocation(this->programObj, "_uvcoords");
	this->normalAttribute = glGetAttribLocation(this->programObj, "_normals");
	this->materialAmbientAttribute = glGetUniformLocation(this->programObj, "_material.ambient");
	this->materialDiffuseAttribute = glGetUniformLocation(this->programObj, "_material.diffuse");
	this->materialSpecularAttribute = glGetUniformLocation(this->programObj, "_material.specular");
	this->materialShineAttribute = glGetUniformLocation(this->programObj, "_material.shine");


	//light
	this->lightColorAttribute = glGetUniformLocation(this->programObj, "_lightcolor");
	this->lightPositionAttribute = glGetUniformLocation(this->programObj, "_lightposition");

	//Those lights affecting the box
	this->greenColorAttribute = glGetUniformLocation(this->programObj, "_light1.color");
	this->greenPositionAttribute = glGetUniformLocation(this->programObj, "_light1.position");
	this->blueColorAttribute = glGetUniformLocation(this->programObj, "_light2.color");
	this->bluePositionAttribute = glGetUniformLocation(this->programObj, "_light2.position");

	//camera
	this->cameraPositionAttribute = glGetUniformLocation(this->programObj, "_cameraposition");
}
void Shader::ApplyShader() {

	this->GetShaderAttributes();

	glLinkProgram(this->programObj);
	glUseProgram(this->programObj);
}