#version 330 core

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec2 a_texUV;
layout(location = 2) in vec3 a_normal;
layout(location = 3) in vec4 a_color;

uniform mat4 u_projectionMatrix;
uniform mat4 u_viewMatrix;
uniform mat4 u_modelMatrix;
uniform mat3 u_normalMatrix;
uniform vec4 u_baseColor;

out vec2 v_texUV;
out vec4 v_color;
out vec3 normal;
out vec4 eye;

void main() {
	gl_Position = u_projectionMatrix * u_viewMatrix * u_modelMatrix * vec4(a_position, 1);
	v_texUV = a_texUV;
	v_color = a_color * u_baseColor;
	
    normal = normalize(u_normalMatrix * a_normal);
    eye = -(u_projectionMatrix * u_viewMatrix * u_modelMatrix * vec4(a_position, 1));
}