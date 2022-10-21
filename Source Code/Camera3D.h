#pragma once
class Camera3D
{
private:
	mat4 view, projection;
	vec3 position, front, up;
public:
	Camera3D();
	~Camera3D();
	float speed;
	float fov;
	void Update(Window window, Shader shader);

	void HandleKeyBoardInput(Window myWindow);
	void HandleMouseInput(Window myWindow);
};