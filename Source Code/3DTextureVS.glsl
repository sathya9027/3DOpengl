#version 330
uniform mat4 _model, _view, _projection;
in vec3 _vertices;
in vec2 _uvcoords;
in vec3 _vs_normals;
out vec2 _texcoords;
out vec3 _fs_normals;
out vec3 _objPos;
void main()
{
	vec4 _local = vec4(_vertices, 1);
	_fs_normals = mat3(transpose(inverse(_model))) * _vs_normals;
	_objPos = vec3(_model*_local);
	gl_Position = _projection * _view * vec4(_objPos, 1);
	_texcoords = _uvcoords;
}