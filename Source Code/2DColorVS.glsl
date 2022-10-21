#version 330
uniform mat4 _model, _view, _projection;
in vec2 _vertices;
in vec3 _color;
out vec3 _fragcolor;
void main()
{
	vec4 _local = vec4(_vertices, 0, 1);
	gl_Position = _projection * _view * _model * _local;
	_fragcolor = _color;
}