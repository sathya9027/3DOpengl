//#version 330
//in vec2 _texcoords;
//in vec3 _fs_normals;
//in vec3 _objPos;
//uniform vec3 _lightColor;
//uniform vec3 _lightPos;
//uniform vec3 _viewPos;
//void main() {
//	vec4 _objColor = texture(_texcolor, _texcoords);
//	float _ambientStrength = 0.5;
//	vec3 _ambient = _ambientStrength * _lightColor;
//	vec3 _normals = normalize(_fs_normals);
//	vec3 _lightDir = normalize(_lightPos - _objPos);
//	float _diffAngle = max(dot(_normals, _lightDir), 0);
//	vec3 _diffuse = _diffAngle * _lightColor;
//	float _specularStrength = 3.5;
//	vec3 _viewDir = normalize(_viewPos - _objPos);
//	vec3 _reflectDir = reflect(_lightDir, _normals);
//	float _specularPos = pow(max(dot(_viewDir, _reflectDir), 0), 32);
//	vec3 _specular = _specularStrength * _specularPos * _lightColor;
//	vec3 _result = vec3((_ambient + _diffuse + _specular) * _objColor.rgb);
//	gl_FragColor = vec4(_result, 1.0);
//}
#version 330

struct Material {
  sampler2D texture;
};

struct Light {
  vec3 color;
  vec3 position;
};

//Uniform and Input variables
uniform Material _material;
uniform Light _light1, _light2;
uniform vec3 _cameraposition;
in vec2  _texcoords;  
in vec3 _lightnormals;
in vec3 _objectposition;

//Local Variables
vec3 _lightdirection, _cameradirection, _reflectdirection;
vec3 _ambient, _diffuse, _specular;
float _angle, _reflectvalue;
uniform sampler2D _texcolor;
  vec3 ambient = vec3(1,1,1);
  vec3 diffuse = vec3(1,1,1);
  vec3 specular=vec3(1,1,1);
  float shine=1;



vec3 calculateLightResult(Light light){

_lightdirection = normalize(light.position - _objectposition);
_cameradirection = normalize(_cameraposition - _objectposition);
    _ambient = light.color * ambient ;
_angle = max(dot(_lightnormals, _lightdirection),0.0);
_diffuse = light.color * ( _angle * diffuse);
_reflectdirection = reflect(-_lightdirection, _lightnormals);
_reflectvalue =  pow(max(dot(_cameradirection,_reflectdirection),0.0), shine);  
_specular =light.color * (_reflectvalue * specular) ;
return (_ambient +_diffuse + _specular);

}

void main()
{
vec4 _objectcolor = texture(_texcolor ,  _texcoords);
vec3 _result1, _result2, _finalresult;

_result1 = calculateLightResult(_light1) ;
_result2 =  calculateLightResult(_light2) ;

//rendering result
    _finalresult = (_result2 + _result1) * _objectcolor.rgb ;
    gl_FragColor = vec4(_finalresult, 1.0);
}