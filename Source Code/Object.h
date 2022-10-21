#pragma once
class Object
{
private:
	bool isTexture;
	mat4 model;
	GLuint VBO, EBO, texture;
public:
	Object();
	~Object();
	void CreateBuffer(float x, float y);
	void CreateBuffer(float x, float y, float r, float g, float b);
	void LoadTexture(const char* filename);
	void Update(vec2 modelPos, Shader shader);
	void Draw(Shader shader);
};

