#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNorm;
layout (location = 2) in vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

flat out vec4 flat_color;
smooth out vec4 smooth_color;
out vec2 mytexCoord;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0);
	gl_PointSize = gl_Position.z * 0.5;
	flat_color = vec4(gl_Position.x * 0.8, gl_Position.y * 0.8 , gl_Position.z * 0.8  , 1.0);
	smooth_color = flat_color;
	mytexCoord = texCoord;
}