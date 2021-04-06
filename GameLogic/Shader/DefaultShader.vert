#version 330 core

layout(location = 0) in vec4 a_position;
layout(location = 1) in vec2 a_texUV;
layout(location = 2) in vec3 a_normal;
layout(location = 3) in vec4 a_color;

out vec2 v_texUV;
out vec3 v_normal;
out vec4 v_color;

void main()
{
	gl_Position = a_position;
	v_texUV = a_texUV;
	v_normal = a_normal;
	v_color = a_color;
}
