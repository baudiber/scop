#version 330 core
out vec4 FragColor;

flat in vec4 flat_color;
smooth in vec4 smooth_color;

uniform int shading;

void main()
{
	if (shading == 0)
	{
		float gray = dot(flat_color.rgb, vec3(0.299, 0.587, 0.114));
		FragColor = vec4(gray, gray, gray, 1.0f);
	}
	else if (shading == 1)
	{
		FragColor = smooth_color;
	}
}
