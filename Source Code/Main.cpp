#include "Common.h"
//draw chair using 6 gameObjects
Window window;
Shader cubeShader;
Shader lightShader;
GameObject leg1;
GameObject leg2;
GameObject leg3;
GameObject leg4;
GameObject seat;
GameObject back;
GameObject light1;
GameObject light2;
Camera3D camera3D;
vec3 gameObjectPos = vec3(0, 0, 0);

void GameObjectMovement() {
	if (glfwGetKey(window.gameWindow, GLFW_KEY_8)) {
		gameObjectPos.y += 0.01;
	}
	if (glfwGetKey(window.gameWindow, GLFW_KEY_2)) {
		gameObjectPos.y -= 0.01;
	}
	if (glfwGetKey(window.gameWindow, GLFW_KEY_4)) {
		gameObjectPos.x -= 0.01;
	}
	if (glfwGetKey(window.gameWindow, GLFW_KEY_6)) {
		gameObjectPos.x += 0.01;
	}
	if (glfwGetKey(window.gameWindow, GLFW_KEY_9)) {
		gameObjectPos.z += 0.01;
	}
	if (glfwGetKey(window.gameWindow, GLFW_KEY_3)) {
		gameObjectPos.z -= 0.01;
	}
	cout << gameObjectPos.x << ", " << gameObjectPos.y << ", " << gameObjectPos.z << endl;
}

void Create() {
	glewInit();
	cubeShader.ShaderInit();
	cubeShader.ProcessShaderFile("3DTextureFS.glsl", GL_FRAGMENT_SHADER);
	cubeShader.ProcessShaderFile("3DTextureVS.glsl", GL_VERTEX_SHADER);
	lightShader.ShaderInit();
	lightShader.ProcessShaderFile("3DLightFS.glsl", GL_FRAGMENT_SHADER);
	lightShader.ProcessShaderFile("3DLightVS.glsl", GL_VERTEX_SHADER);
	leg1.CreateBuffers(0.025, 0.25, 0.025);
	leg1.LoadTexture("leg.png");
	leg2.CreateBuffers(0.025, 0.25, 0.025);
	leg2.LoadTexture("leg.png");
	leg3.CreateBuffers(0.025, 0.25, 0.025);
	leg3.LoadTexture("leg.png");
	leg4.CreateBuffers(0.025, 0.25, 0.025);
	leg4.LoadTexture("leg.png");
	seat.CreateBuffers(0.25, 0.05, 0.25);
	seat.LoadTexture("seat.png");
	back.CreateBuffers(0.25, 0.25, 0.05);
	back.LoadTexture("seat.png");
	light1.CreateBuffers(vec3(0.05, 0.05, 0.05));
	light2.CreateBuffers(vec3(0.05, 0.05, 0.05));
	glEnable(GL_DEPTH_TEST); 
	glfwSetInputMode(window.gameWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);		//cursor invisible
}

void Render() {
	lightShader.ApplyShader();
	camera3D.Update(window, lightShader);

	light1.lightColor = vec3(1, 1, 0);
	light1.Update(vec3(1, 1, 0), lightShader);
	light1.Draw(lightShader);

	light2.lightColor = vec3(1, 0, 1);
	light2.Update(vec3(-1, -1, 0), lightShader);
	light2.Draw(lightShader);

	cubeShader.ApplyShader();
	camera3D.Update(window, cubeShader);
	camera3D.HandleKeyBoardInput(window);
	camera3D.HandleMouseInput(window);

	leg1.Update(vec3(0.315001, -0.2245, 0.106), cubeShader, light1, light2);//
	leg1.Draw(cubeShader);
	leg2.Update(vec3(-0.229, -0.253, -0.218), cubeShader, light1, light2);//
	leg2.Draw(cubeShader);
	leg3.Update(vec3(0.1914, -0.1281, -0.3136), cubeShader, light1, light2);//
	leg3.Draw(cubeShader);
	leg4.Update(vec3(-0.1063, -0.347001, 0.2028), cubeShader, light1, light2);//
	leg4.Draw(cubeShader);
	seat.Update(vec3(0, -0.05, 0), cubeShader, light1, light2);//
	seat.Draw(cubeShader);
	back.Update(vec3(-0.1192, 0.2732, -0.105), cubeShader, light1, light2);//
	back.Draw(cubeShader);

	//GameObjectMovement();
}

int main() {
	window.CreateGameWindow(800, 800, "My Game Window", false);
	Create();
	do {
		window.SetBGColor(0.1, 0.25, 0.3, 0);
		Render();
		window.UpdateWindow();
	} while (window.IsWindowNotClosed());
	return 0;
}