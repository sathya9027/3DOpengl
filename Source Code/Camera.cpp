#include "Common.h"
Camera::Camera() {
	this->position = vec3(0, 0, 1);
	this->target = vec3(0, 0, 0);
	this->orientation = vec3(0, 1, 0);
	this->view = mat4(1);
	this->projection = mat4(1);
}
Camera::~Camera() {

}
void Camera::Update(Window window, Shader shader) {
	this->view = mat4(1);
	this->view = lookAt(this->position, this->target, this->orientation);
	glUniformMatrix4fv(shader.viewAttribute, 1, GL_FALSE, value_ptr(this->view));
	
	this->projection = mat4(1);
	this->projection = ortho(0.f, window.windowWidth, 0.0f,  window.windowHeight, 1.0f, 1000.0f);
	//left, right, top, bottom
	glUniformMatrix4fv(shader.projectionAttribute, 1, GL_FALSE, value_ptr(this->projection));
}
