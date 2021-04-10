#version 330 core

in vec2 v_texUV;
in vec4 v_color;
in vec3 normal;
in vec4 eye;

uniform sampler2D u_texture;

layout(location = 0) out vec4 f_color;

void main() {
	vec4 texColor = texture(u_texture, v_texUV);
	
    // set the specular term to black
    vec4 spec = vec4(0.0);

    // normalize both input vectors
    vec3 n = normalize(normal);
    vec3 e = normalize(vec3(eye));
    
    vec3 direction = vec3(-0.8,-0.8,0);
    
    float intensity = max(dot(n,direction), 0.0);
    // if the vertex is lit compute the specular color
    if (intensity > 0.0) {
        // compute the half vector
        vec3 h = normalize(direction + e);
        // compute the specular term into spec
        float intSpec = max(dot(h,n), 0.0);
        spec = vec4(0.1) * pow(intSpec,0.01);
    }

	f_color = v_color * texColor * min(max(intensity + spec, vec4(0.1)), 1.0f);
}