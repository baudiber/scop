#include <libgraph.h>

bool float_cmp(float float1, float float2)
{
    return (fabsf(float1 - float2) < FLT_EPSILON);
}
