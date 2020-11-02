#include <scop.h>

void 		malloc_buffers(t_env *e)
{
    if (!(e->data.v = (t_vec3 *)malloc(sizeof(t_vec3) * e->data_size.v_nb)))
        clean_exit("malloc error");
    if (!(e->data.indices = (t_vec3_int *)malloc(sizeof(t_vec3_int)
		* e->data_size.indice_nb)))
        clean_exit("malloc error");
    if (e->mesh.has_vts)
    {
        if (!(e->data.vt = (t_vec2 *)malloc(sizeof(t_vec2)
			* e->data_size.vt_nb)))
            clean_exit("malloc error");
    }
    if (e->mesh.has_vns)
    {
        if (!(e->data.vn = (t_vec3 *)malloc(sizeof(t_vec3)
			* e->data_size.vn_nb)))
            clean_exit("malloc error");
	}
}

void 	malloc_vertices(t_env *e)
{
    if (!(e->mesh.verts = (t_vertex *)malloc(sizeof(t_vertex)
		* e->data_size.vert_nb)))
        clean_exit("verts malloc error");
    if (!(e->mesh.index_buffer = (unsigned int *)malloc(sizeof(unsigned int)
		* e->data_size.indice_nb)))
        clean_exit("index_buffer malloc error");
}

void    free_raw_data(t_env *e)
{
    free(e->data.v);
    if (e->mesh.has_vns)
        free(e->data.vn);
    if (e->mesh.has_vts)
        free(e->data.vt);
    free(e->data.indices);
}

void 	malloc_vert_list(t_env *e)
{
    e->vert_lst = (t_vert_lst *)malloc(sizeof(t_vert_lst));
    if (!e->vert_lst)
        clean_exit("malloc error");
}

