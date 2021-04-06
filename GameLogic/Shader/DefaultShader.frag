#version 330 core

in vec2 v_texUV;
in vec3 v_normal;
in vec4 v_color;
uniform sampler2D u_texture;

layout(location = 0) out vec4 f_color;

void main(){
	vec4 texColor = texture(u_texture, v_texUV);
	f_color = v_color * texColor;
}