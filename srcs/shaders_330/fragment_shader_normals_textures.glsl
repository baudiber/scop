#version 330 core
out vec4 FragColor;

flat in vec4 norm_color;
in vec2 mytexCoord;

uniform int shading;
uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float transition;

void main()
{
	if (shading == 0)
	{
		float gray = dot(norm_color.rgb, vec3(0.299, 0.587, 0.114));
		FragColor = vec4(gray, gray, gray, 1.0f);
	}
	else if (shading == 1)
	{
		FragColor = norm_color;
	}
	else if (shading == 2)
	{
		FragColor = mix(norm_color, texture(texture1, mytexCoord), transition);
	}
	else
	{
		FragColor = texture(texture2, mytexCoord);
	}
}
