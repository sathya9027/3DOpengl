#version 330
in vec2 _texcoords;
uniform sampler2D _texcolor;
void main() {
	gl_FragColor = texture(_texcolor, _texcoords);
}