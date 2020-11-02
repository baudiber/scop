#include <scop.h>

void 	normalize_mesh(t_env *e)
{
    unsigned int 	i;
    float 			scale;

    scale = fmin(2.0f / (e->data_size.max.x - e->data_size.min.x),
                 fmin(2.0f / (e->data_size.max.y - e->data_size.min.y),
                      2.0f / (e->data_size.max.z - e->data_size.max.z)));
    i = 0;
    while (i < e->data_size.v_nb)
    {
        e->data.v[i].x = (e->data.v[i].x - 0.5 * (e->data_size.min.x
                                                  + e->data_size.max.x)) * scale;
        e->data.v[i].y = (e->data.v[i].y - 0.5 * (e->data_size.min.y
                                                  + e->data_size.max.y)) * scale;
        e->data.v[i].z = (e->data.v[i].z - 0.5 * (e->data_size.min.z
                                                  + e->data_size.max.z)) * scale;
        i++;
    }
}

void 	get_min_max(t_env *e)
{
    unsigned int 	i;

    i = 0;
    e->data_size.min.x = e->data.v[i].x;
    e->data_size.max.x = e->data.v[i].x;
    e->data_size.min.y = e->data.v[i].y;
    e->data_size.max.y = e->data.v[i].y;
    e->data_size.min.z = e->data.v[i].z;
    e->data_size.max.z = e->data.v[i].z;
    while (i < e->data_size.v_nb)
    {
        if (e->data.v[i].x < e->data_size.min.x)
            e->data_size.min.x = e->data.v[i].x;
        else if (e->data.v[i].x > e->data_size.max.x)
            e->data_size.max.x = e->data.v[i].x;
        if (e->data.v[i].y < e->data_size.min.y)
            e->data_size.min.y = e->data.v[i].y;
        else if (e->data.v[i].y > e->data_size.max.y)
            e->data_size.max.y = e->data.v[i].y;
        if (e->data.v[i].z < e->data_size.min.z)
            e->data_size.min.z = e->data.v[i].z;
        else if (e->data.v[i].z > e->data_size.max.z)
            e->data_size.max.z = e->data.v[i].z;
        i++;
    }
}

