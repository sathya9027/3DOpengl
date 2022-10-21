#include "Common.h"

const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 800;
float _pitch, _yaw, fov;
float LastX, LastY;
float Xoffset, Yoffset;
float sensitivity;
bool isFirst;

float speed;
float ypos;

vec3 newFront;
Camera3D::Camera3D() {
	this->position = vec3(0, 0, 3);
	this->front = vec3(1, 1, -1);
	this->up = vec3(0, 1, 0);
	this->view = mat4(1);
	this->projection = mat4(1);
	this->speed = 0.05f;
	this->fov = 45.0f;
	_pitch = 0.0f;
	_yaw = -90.0f;
	LastX = (float)SCR_WIDTH / 2.0f;
	LastY = (float)SCR_HEIGHT / 2.0f;
	Xoffset = 0.1f;
	Yoffset = 0.1f;
	sensitivity = 0.05f;
	isFirst = true;
	newFront = this->front;
}
Camera3D::~Camera3D() {

}
void Camera3D::Update(Window window, Shader shader) {
	this->front = newFront;
	this->view = mat4(1);
	this->view = lookAt(this->position, this->position + this->front, this->up);
	glUniformMatrix4fv(shader.viewAttribute, 1, GL_FALSE, value_ptr(this->view));

	this->projection = mat4(1);
	this->projection = perspective(radians(this->fov), (float)(window.windowWidth / window.windowHeight), 0.1f, 100.0f);
	glUniformMatrix4fv(shader.projectionAttribute, 1, GL_FALSE, value_ptr(this->projection));
	glUniform3f(shader.cameraPositionAttribute, this->position.x, this->position.y, this->position.z);
}


void mouse_callback(GLFWwindow* window, double xPos, double yPos)
{
	if (isFirst)
	{
		LastX = xPos;
		LastY = yPos;
		isFirst = false;
	}


	Xoffset = xPos - LastX;
	Yoffset = yPos - LastY;

	LastX = xPos;
	LastY = yPos;

	Xoffset *= sensitivity;
	Yoffset *= sensitivity;

	_yaw += Xoffset;
	_pitch += Yoffset;


	//if (_pitch > 89.0f)
	//	_pitch = 89.0f;
	//if (_pitch < -89.0f)
	//	_pitch = -89.0f;

	newFront.x = cos(radians(_yaw)) * cos(radians(_pitch));
	newFront.y = sin(radians(_pitch));
	newFront.z = sin(radians(_yaw)) * cos(radians(_pitch));
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	ypos = yoffset;
	cout << ypos << endl;
}

void  Camera3D::HandleMouseInput(Window myWindow) {
	glfwSetCursorPosCallback(myWindow.gameWindow, mouse_callback);
	glfwSetScrollCallback(myWindow.gameWindow, scroll_callback);
}

void Camera3D::HandleKeyBoardInput(Window myWindow) {

	if (ypos != 0) {
		if (ypos > 0) {
			this->position += this->front * speed;
		}
		if (ypos < 0) {
			this->position -= this->front * speed;
		}
	}
	if (glfwGetKey(myWindow.gameWindow, GLFW_KEY_A)) {
		this->position += normalize(cross(this->front, this->up)) * speed;
	}
	if (glfwGetKey(myWindow.gameWindow, GLFW_KEY_D)) {
		this->position -= normalize(cross(this->front, this->up)) * speed;
	}
	if (glfwGetKey(myWindow.gameWindow, GLFW_KEY_W)) {
		this->position -= vec3(0, 1 * speed, 0);
	}
	if (glfwGetKey(myWindow.gameWindow, GLFW_KEY_S)) {
		this->position += vec3(0, 1 * speed, 0);
	}
	if (glfwGetKey(myWindow.gameWindow, GLFW_KEY_R)) {
		this->position = vec3(0, 0, 3);
	}
	if (glfwGetKey(myWindow.gameWindow, GLFW_KEY_LEFT_SHIFT)) {
		speed = 0.001f;
	}
	else {
		speed = 0.005f;
	}
}