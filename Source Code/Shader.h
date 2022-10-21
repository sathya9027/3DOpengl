#pragma once
class Shader
{
public:
	Shader();
	~Shader();
	GLuint programObj;
	GLuint vertexAttribute, colorAttribute, uvAttribute;
	GLuint modelAttribute, viewAttribute, projectionAttribute;
	GLuint lightAttribute, normalAttribute;
	GLuint lightPosAttribute, viewPosAttribute;
	GLuint materialAmbientAttribute, materialDiffuseAttribute, materialSpecularAttribute, materialShineAttribute;
	GLuint lightColorAttribute, lightPositionAttribute;
	GLuint greenColorAttribute, greenPositionAttribute, blueColorAttribute, bluePositionAttribute;
	GLuint cameraPositionAttribute;
	string ReadShaderFile(const char* filename);
	void ShaderInit();
	void ProcessShaderFile(const char* filename, GLenum shaderType);
	void GetShaderAttributes();
	void ApplyShader();
};