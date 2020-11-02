#include <libgraph.h>

bool float_cmp(float float1, float float2)
{
    return (fabsf(float1 - float2) < FLT_EPSILON);
}

t_vec4 vec4(float x, float y, float z)
{
	t_vec4 ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	ret.w = 1.0f;
	return (ret);
}

t_vec3 vec3(float x, float y, float z)
{
	t_vec3 ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_vec2 vec2(float x, float y)
{
	t_vec2 ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}
