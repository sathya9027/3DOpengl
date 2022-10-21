#version 330
uniform mat4 _model, _view, _projection;
in vec3 _vertices;
void main()
{
	vec4 _local = vec4(_vertices, 1);
	gl_Position = _projection * _view * _model * _local;
}