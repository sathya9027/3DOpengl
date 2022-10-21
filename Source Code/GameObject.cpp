#include "Common.h"
GameObject::GameObject() {
	this->texture = NULL;
	this->isTexture = NULL;
	this->isLight = NULL;
	this->VBO = NULL;
	this->EBO = NULL;
	this->model = mat4(1);
	this->lightColor = vec3(1, 1, 1);
}
GameObject::~GameObject() {

}

void GameObject::CreateBuffers(float x, float y, float z) {
	this->isTexture = true;
	GLfloat data[] = {
		-x, -y, -z,		1, 0,		0, 0, -1,
		x, -y, -z,		1, 1,		0, 0, -1,
		x,  y, -z,		0, 1,		0, 0, -1,
		-x,  y, -z,		0, 0,		0, 0, -1,

		-x, -y,  z,		1, 0,		0, 0, 1,
		x, -y,  z,		1, 1,		0, 0, 1,
		x,  y,  z,		0, 1,		0, 0, 1,
		-x,  y,  z,		0, 0,		0, 0, 1,

		-x,  y,  z,		1, 0,		-1, 0, 0,
		-x,  y, -z,		1, 1,		-1, 0, 0,
		-x, -y, -z,		0, 1,		-1, 0, 0,
		-x, -y,  z,		0, 0,		-1, 0, 0,

		x,  y,  z,		1, 0,		1, 0, 0,
		x,  y, -z,		1, 1,		1, 0, 0,
		x, -y, -z,		0, 1,		1, 0, 0,
		x, -y,  z,		0, 0,		1, 0, 0,

		-x, -y, -z,		1, 0,		0, -1, 0,
		x, -y, -z,		1, 1,		0, -1, 0,
		x, -y,  z,		0, 1,		0, -1, 0,
		-x, -y,  z,		0, 0,		0, -1, 0,

		-x,  y, -z,		1, 0,		0, 1, 0,
		x,  y, -z,		1, 1,		0, 1, 0,
		x,  y,  z,		0, 1,		0, 1, 0,
		-x,  y,  z,		0, 0,		0, 1, 0
	};

	glGenBuffers(1, &this->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
	
	GLuint indices[] = {
		0, 1, 2,
		2, 3, 0,

		4, 5, 6,
		6, 7, 4,

		8, 9, 10,
		10, 11, 8,

		12, 13, 14,
		14, 15, 12,

		16, 17, 18,
		18, 19, 16,

		20, 21, 22,
		22, 23, 20
	};

	glGenBuffers(1, &(this->EBO));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}
void GameObject::CreateBuffers(vec3 lightSize) {
	this->isLight = true;
	GLfloat data[] = {
		-lightSize.x, -lightSize.y, -lightSize.z,		1, 0,		0, 0, -1,
		lightSize.x, -lightSize.y, -lightSize.z,		1, 1,		0, 0, -1,
		lightSize.x,  lightSize.y, -lightSize.z,		0, 1,		0, 0, -1,
		-lightSize.x,  lightSize.y, -lightSize.z,		0, 0,		0, 0, -1,

		-lightSize.x, -lightSize.y,  lightSize.z,		1, 0,		0, 0, 1,
		lightSize.x, -lightSize.y,  lightSize.z,		1, 1,		0, 0, 1,
		lightSize.x,  lightSize.y,  lightSize.z,		0, 1,		0, 0, 1,
		-lightSize.x,  lightSize.y,  lightSize.z,		0, 0,		0, 0, 1,

		-lightSize.x,  lightSize.y,  lightSize.z,		1, 0,		-1, 0, 0,
		-lightSize.x,  lightSize.y, -lightSize.z,		1, 1,		-1, 0, 0,
		-lightSize.x, -lightSize.y, -lightSize.z,		0, 1,		-1, 0, 0,
		-lightSize.x, -lightSize.y,  lightSize.z,		0, 0,		-1, 0, 0,

		lightSize.x,  lightSize.y,  lightSize.z,		1, 0,		1, 0, 0,
		lightSize.x,  lightSize.y, -lightSize.z,		1, 1,		1, 0, 0,
		lightSize.x, -lightSize.y, -lightSize.z,		0, 1,		1, 0, 0,
		lightSize.x, -lightSize.y,  lightSize.z,		0, 0,		1, 0, 0,

		-lightSize.x, -lightSize.y, -lightSize.z,		1, 0,		0, -1, 0,
		lightSize.x, -lightSize.y, -lightSize.z,		1, 1,		0, -1, 0,
		lightSize.x, -lightSize.y,  lightSize.z,		0, 1,		0, -1, 0,
		-lightSize.x, -lightSize.y,  lightSize.z,		0, 0,		0, -1, 0,

		-lightSize.x,  lightSize.y, -lightSize.z,		1, 0,		0, 1, 0,
		lightSize.x,  lightSize.y, -lightSize.z,		1, 1,		0, 1, 0,
		lightSize.x,  lightSize.y,  lightSize.z,		0, 1,		0, 1, 0,
		-lightSize.x,  lightSize.y,  lightSize.z,		0, 0,		0, 1, 0
	};

	glGenBuffers(1, &this->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
	
	GLuint indices[] = {
		0, 1, 2,
		2, 3, 0,

		4, 5, 6,
		6, 7, 4,

		8, 9, 10,
		10, 11, 8,

		12, 13, 14,
		14, 15, 12,

		16, 17, 18,
		18, 19, 16,

		20, 21, 22,
		22, 23, 20
	};

	glGenBuffers(1, &(this->EBO));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}
void GameObject::CreateBuffers(float x, float y, float z, float r, float g, float b) {
	this->isTexture = false;
	GLfloat data[] = {
		-x, -y, -z,		 r, g, b,		0, 0, -1,
		x, -y, -z,		 r, g, b,		0, 0, -1,
		x,  y, -z,		 r, g, b,		0, 0, -1,
		-x,  y, -z,		 r, g, b,		0, 0, -1,

		-x, -y,  z,		 r, g, b,		0, 0, 1,
		x, -y,  z,		 r, g, b,		0, 0, 1,
		x,  y,  z,		 r, g, b,		0, 0, 1,
		-x,  y,  z,		 r, g, b,		0, 0, 1,

		-x,  y,  z,		 r, g, b,		-1, 0, 0,
		-x,  y, -z,		 r, g, b,		-1, 0, 0,
		-x, -y, -z,		 r, g, b,		-1, 0, 0,
		-x, -y,  z,		 r, g, b,		-1, 0, 0,

		x,  y,  z,		 r, g, b,		1, 0, 0,
		x,  y, -z,		 r, g, b,		1, 0, 0,
		x, -y, -z,		 r, g, b,		1, 0, 0,
		x, -y,  z,		 r, g, b,		1, 0, 0,

		-x, -y, -z,		 r, g, b,		0, -1, 0,
		x, -y, -z,		 r, g, b,		0, -1, 0,
		x, -y,  z,		 r, g, b,		0, -1, 0,
		-x, -y,  z,		 r, g, b,		0, -1, 0,

		-x,  y, -z,		 r, g, b,		0, 1, 0,
		x,  y, -z,		 r, g, b,		0, 1, 0,
		x,  y,  z,		 r, g, b,		0, 1, 0,
		-x,  y,  z,		 r, g, b,		0, 1, 0,
	};

	glGenBuffers(1, &this->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

	GLuint indices[] = {
		0, 1, 2,
		2, 3, 0,

		4, 5, 6,
		6, 7, 4,

		8, 9, 10,
		10, 11, 8,

		12, 13, 14,
		14, 15, 12,

		16, 17, 18,
		18, 19, 16,

		20, 21, 22,
		22, 23, 20
	};

	glGenBuffers(1, &(this->EBO));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}
void GameObject::LoadTexture(const char* filename) {
	glGenTextures(1, &this->texture);
	this->texture = SOIL_load_OGL_texture(
		filename,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		4
	);
}
void GameObject::Update(vec3 modelPos, Shader shader, GameObject lightObject) {
	this->model = mat4(1.0f);
	this->model = translate(this->model, vec3(modelPos.x, modelPos.y, modelPos.z));
	this->model = rotate(this->model, (float)radians(25.0f), vec3(1, 1, 1));
	glUniformMatrix4fv(shader.modelAttribute, 1, GL_FALSE, value_ptr(this->model)); 
	glUniform3f(shader.lightAttribute, lightObject.lightColor.x, lightObject.lightColor.y, lightObject.lightColor.z);
}
void GameObject::Update(vec3 modelPos, Shader shader, GameObject light1, GameObject light2) {
	this->model = mat4(1.0f);
	this->model = translate(this->model, vec3(modelPos.x, modelPos.y, modelPos.z));
	this->model = rotate(this->model, (float)radians(25.0f), vec3(1, 1, 1));
	glUniformMatrix4fv(shader.modelAttribute, 1, GL_FALSE, value_ptr(this->model)); 

	glUniform3f(shader.greenColorAttribute, light1.lightColor.x, light1.lightColor.y, light1.lightColor.z);
	glUniform3f(shader.blueColorAttribute, light2.lightColor.x, light2.lightColor.y, light2.lightColor.z);

	glUniform3f(shader.greenPositionAttribute, light1.lightPos.x, light1.lightPos.y, light1.lightPos.z);
	glUniform3f(shader.bluePositionAttribute, light2.lightPos.x, light2.lightPos.y, light2.lightPos.z);
}
void GameObject::Update(vec3 modelPos, Shader shader) {
	this->lightPos = modelPos;
	this->model = mat4(1.0f);
	this->model = translate(this->model, vec3(modelPos.x, modelPos.y, modelPos.z));
	this->model = rotate(this->model, (float)radians(25.0f), vec3(1, 1, 1));
	glUniformMatrix4fv(shader.modelAttribute, 1, GL_FALSE, value_ptr(this->model));
	glUniform3f(shader.lightPosAttribute, modelPos.x, modelPos.y, modelPos.z);
	glUniform3f(shader.lightAttribute, lightColor.x, lightColor.y, lightColor.z);
}
void GameObject::Draw(Shader shader) {
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	if (isTexture || isLight) {
		glVertexAttribPointer(shader.vertexAttribute, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glVertexAttribPointer(shader.uvAttribute, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glVertexAttribPointer(shader.normalAttribute, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
		glEnableVertexAttribArray(shader.uvAttribute);
		glBindTexture(GL_TEXTURE_2D, this->texture);
	}
	else {
		glVertexAttribPointer(shader.vertexAttribute, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
		glVertexAttribPointer(shader.colorAttribute, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
		glVertexAttribPointer(shader.normalAttribute, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(shader.colorAttribute);
	}
	glEnableVertexAttribArray(shader.vertexAttribute);
	glEnableVertexAttribArray(shader.normalAttribute);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}
