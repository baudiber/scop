#include <scop.h>

bool        init_lists(t_env *e)
{
    e->v_lst = (t_v_lst *)malloc(sizeof(t_v_lst));
    e->f_lst = (t_f_lst *)malloc(sizeof(t_f_lst));
    e->vt_lst = (t_vt_lst *)malloc(sizeof(t_vt_lst));
    e->vn_lst = (t_vn_lst *)malloc(sizeof(t_vn_lst));
    if (!e->v_lst || !e->f_lst || !e->vt_lst || !e->vn_lst)
        return (false);
    return (true);
}

void        init_iterator_struct(t_list_iterators *iterators, t_env *e)
{
    iterators->v_it = e->v_lst;
    iterators->f_it = e->f_lst;
    iterators->vt_it = e->vt_lst;
    iterators->vn_it = e->vn_lst;
    iterators->v_nb = 0;
    iterators->vt_nb = 0;
    iterators->vn_nb = 0;
    iterators->i_nb = 0;
}

void free_vert_lst(t_env *e)
{
    t_vert_lst *it;

    it = e->vert_lst;
    while (it)
    {
        free(it);
        it = it->next;
    }
}
void        free_normal_texcoords_lists(t_env *e)
{
    t_vt_lst 	*vt_it;
    t_vn_lst 	*vn_it;

    vt_it = e->vt_lst;
     vn_it = e->vn_lst;
    if (e->mesh.has_vts)
    {
        while (vt_it)
        {
            free(vt_it);
            vt_it = vt_it->next;
        }
    }
    if (e->mesh.has_vns)
    {
        while (vn_it)
        {
            free(vn_it);
            vn_it = vn_it->next;
        }
    }
}

void 		free_lists(t_env *e)
{
    t_f_lst 	*f_it;
    t_v_lst 	*v_it;

    v_it = e->v_lst;
    f_it = e->f_lst;
    while (f_it)
    {
        free(f_it);
        f_it = f_it->next;
    }
    while (v_it)
    {
        free(v_it);
        v_it = v_it->next;
    }
    free_normal_texcoords_lists(e);
}
