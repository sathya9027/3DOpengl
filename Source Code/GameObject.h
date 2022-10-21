#pragma once
class GameObject
{
private:
	bool isTexture;
	bool isLight;
	GLuint VBO, EBO, texture;
	mat4 model;
public:
	GameObject();
	~GameObject();
	vec3 lightColor;
	vec3 lightPos;
	void CreateBuffers(vec3 lightSize);
	void CreateBuffers(float x, float y, float z);
	void CreateBuffers(float x, float y, float z, float r, float g, float b);
	void LoadTexture(const char* filename);
	void Update(vec3 modelPos, Shader shader, GameObject lightObject);
	void Update(vec3 modelPos, Shader shader, GameObject light1, GameObject light2);
	void Update(vec3 modelPos, Shader shader);
	void Draw(Shader shader);
};

