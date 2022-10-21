#include "Common.h"
Object::Object() {
	this->VBO = NULL;
	this->EBO = NULL;
	this->texture = NULL;
	this->isTexture = NULL;
	this->model = mat4(1.0f);
}
Object::~Object() {

}
void Object::CreateBuffer(float x, float y) {
	this->isTexture = true;
	GLfloat texdata[] = {
		x, y,		1,0,
		x, -y,		1,1,
		-x, -y,		0,1,
		-x, y,		0,0
	};

	glGenBuffers(1, &(this->VBO));
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texdata), texdata, GL_STATIC_DRAW);

	GLuint indices[] = {
		0,1,2,
		2,3,0
	};

	glGenBuffers(1, &(this->EBO));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}
void Object::CreateBuffer(float x, float y, float r, float g, float b) {
	this->isTexture = false;
	GLfloat colordata[] = {
		x, y,		r,g,b,
		x, -y,		r,g,b,
		-x, -y,		r,g,b,
		-x, y,		r,g,b,
	};

	glGenBuffers(1, &(this->VBO));
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colordata), colordata, GL_STATIC_DRAW);

	GLuint indices[] = {
		0,1,2,
		2,3,0
	};

	glGenBuffers(1, &(this->EBO));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}
void Object::LoadTexture(const char* filename) {
	glGenTextures(1, &this->texture);
	this->texture = SOIL_load_OGL_texture(
		filename,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		4
	);
}
void Object::Update(vec2 modelPos, Shader shader) {
	this->model = mat4(1.0f);
	this->model = translate(this->model, vec3(modelPos.x, modelPos.y, 0.0f));
	glUniformMatrix4fv(shader.modelAttribute, 1, GL_FALSE, value_ptr(this->model));
}
void Object::Draw(Shader shader) {
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	if (isTexture) {
		glVertexAttribPointer(shader.vertexAttribute, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glVertexAttribPointer(shader.uvAttribute, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(shader.uvAttribute);
		glBindTexture(GL_TEXTURE_2D, this->texture);
	}
	else {
		glVertexAttribPointer(shader.vertexAttribute, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glVertexAttribPointer(shader.colorAttribute, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(shader.colorAttribute);
	}
	glEnableVertexAttribArray(shader.vertexAttribute);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
