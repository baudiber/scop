#include <scop.h>

void    parse_v_line(const char *line, t_list_iterators *iterators)
{
    t_v_lst *new;

    if (!(new = (t_v_lst *)malloc(sizeof(t_v_lst))))
        clean_exit("malloc error");
    if ((sscanf(line, "v %f %f %f", &new->pos.x, &new->pos.y, &new->pos.z)) != 3)
        clean_exit("sscanf error");
    new->next = NULL;
    iterators->v_it->next = new;
    iterators->v_it = iterators->v_it->next;
    iterators->v_nb++;
}

void    parse_vt_line(const char *line, t_list_iterators *iterators)
{
    t_vt_lst *new;

    if (!(new = (t_vt_lst *)malloc(sizeof(t_vt_lst))))
        clean_exit("malloc error");
    if ((sscanf(line, "vt %f %f", &new->uv.x, &new->uv.y)) != 2)
        clean_exit("sscanf error");
    new->next = NULL;
    iterators->vt_it->next = new;
    iterators->vt_it = iterators->vt_it->next;
    iterators->vt_nb++;
}

//void    parse_vn_line(const char *line, t_list_iterators *iterators)
//{
//    t_vn_lst *new;
//
//    if (!(new = (t_vn_lst *)malloc(sizeof(t_vn_lst))))
//        clean_exit("malloc error");
//    if ((sscanf(line, "v %f %f %f", &new->pos.x, &new->pos.y, &new->pos.z)) != 3)
//        clean_exit("sscanf error");
//    new->next = NULL;
//    iterators->vn_it->next = new;
//    iterators->vn_it = iterators->vn_it->next;
//    iterators->vn_nb++;
//}

void        parse_line(char *line, t_list_iterators *iterators, t_env *e)
{
    if (line && !ft_strncmp(line, "v ", 2))
        parse_v_line(line, iterators);
        //else if (line && !ft_strncmp(line, "vn ", 3))
        //{
        //    e->mesh.has_vns = true;
        //    parse_vn_line(line, iterators);
        //}
    else if (line && !ft_strncmp(line, "vt ", 3))
    {
        e->mesh.has_vts = true;
        e->mesh.textured = true;
        parse_vt_line(line, iterators);
    }
    else if (line && !ft_strncmp(line, "f ", 2))
    {
        //if (e->mesh.has_vts && e->mesh.has_vns)
        // 	parse_face_line_vts_vns(line, iterators);
        if (e->mesh.has_vts)
            parse_face_line_vts(line, iterators);
            //  else if (e->mesh.has_vns)
            //      parse_face_line_vns(line, iterators);
        else
            parse_face_line(line, iterators);
    }
}
