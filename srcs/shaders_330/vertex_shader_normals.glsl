#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNorm;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

flat out vec4 flat_color;
flat out vec4 norm_color;
smooth out vec4 smooth_color;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0);
	gl_PointSize = gl_Position.z * 0.5;
	flat_color = vec4(gl_Position.x * 0.8, gl_Position.y * 0.8 , gl_Position.z * 0.8  , 1.0);
	norm_color = vec4(0.4f + aNorm.x, 0.6f + aNorm.y, 0.5f + aNorm.z, 1.0f);
	smooth_color = flat_color;
}
