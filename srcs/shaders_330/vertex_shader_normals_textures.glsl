#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNorm;
layout (location = 2) in vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

flat out vec4 norm_color;
out vec2 mytexCoord;

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0);
	gl_PointSize = gl_Position.z * 0.5;
	norm_color = vec4(0.4f + aNorm.x, 0.6f + aNorm.y, 0.5f + aNorm.z, 1.0f);
	mytexCoord = texCoord;
}
