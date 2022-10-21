#version 330
uniform vec3 _lightColor;
void main() {
	gl_FragColor = vec4(_lightColor, 1);
}