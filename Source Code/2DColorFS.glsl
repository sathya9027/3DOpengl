#version 330
in vec3 _fragcolor;
void main() {
	gl_FragColor = vec4(_fragcolor, 0.0);
}