#include "../../includes/scop.h"
#include <stdio.h>

// # for comments
// v  for vectors               followed by x y z w                      w is optional and will default to 1.0
// vp for free-form geometry
// mtllib <.mtl file>
// o object
// usemtl <material name>
// s on/off
// f  for faces   followed by vectex by index (starting at 1)

void 		free_lists(t_env *e)
{
	t_f_lst 	*f_it;
	t_v_lst 	*v_it;
	t_vt_lst 	*vt_it;

	v_it = e->v_lst->next;
	f_it = e->f_lst;
	vt_it = e->vt_lst;
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
	while (vt_it)
	{
		free(vt_it);
		vt_it = vt_it->next;
	}
}

void 		malloc_buffers(t_env *e)
{
	if (!(e->mesh.verts = (t_vertex *)malloc(sizeof(t_vertex) * e->data_size.vec_nb)))
	{
		printf("malloc error");
		exit(-1);
	}
	if (!(e->mesh.indices = (unsigned int *)malloc(sizeof(unsigned int) * e->data_size.indice_nb)))
	{
		printf("malloc error");
		exit(-1);
	}
	if (e->mesh.textured)
	{
		if (!(e->mesh.text_coords = (unsigned int *)malloc(sizeof(unsigned int) * e->data_size.indice_nb)))
		{
			printf("malloc error");
			exit(-1);
		}
	}
}

void 		process_fdata(t_env *e)
{
	t_f_lst 	*f_it;
	int 			i;

	f_it = e->f_lst->next;
	i = 0;
	while (f_it)
	{
		e->mesh.indices[i] = f_it->indices[0];
		e->mesh.indices[i + 1] = f_it->indices[1];
		e->mesh.indices[i + 2] = f_it->indices[2];
		if (f_it->nb == 4)
			e->mesh.indices[i + 3] = f_it->indices[3];
		if (e->mesh.textured)
		{
			e->mesh.text_coords[i] = f_it->tex_cords[0];
			e->mesh.text_coords[i + 1] = f_it->tex_cords[1];
			e->mesh.text_coords[i + 2] = f_it->tex_cords[2];
			if (f_it->nb == 4)
				e->mesh.text_coords[i + 3] = f_it->tex_cords[3];
		}
		i += f_it->nb;
		f_it = f_it->next;
	}
}

void 	process_data(t_env *e)
{
	t_vertex out_verts[e->data_size.v_nb];
	int  ov_i;
	
	ov_i = 0;
	for (unsigned int i = 0; i < e->data_size.indice_nb; i++)
	{
		out_verts[ov_i].pos = e->mesh.verts[e->mesh.indices[i]].pos;
		out_verts[ov_i].text_coords.x = e->mesh.
	}

}

void 		process_vdata(t_env *e)
{
	t_vt_lst 		*vt_it;
	int 			i;

	vt_it = e->vt_lst->next;
	i = 0;
	while (vt_it)
	{
		e->mesh.verts[i].text_coords[0] = vt_it->u;
		e->mesh.verts[i].text_coords[1] = vt_it->v;
		vt_it = vt_it->next;
		i++;
	}
}

void 		process_vdata(t_env *e)
{
	t_v_lst 		*v_it;
	int 			i;

	v_it = e->v_lst->next;
	i = 0;
	while (v_it)
	{
		e->mesh.verts[i].pos = v_it->pos;
		v_it = v_it->next;
		i++;
	}
}

t_vt_lst 	*parse_vt_line(const char *line)
{
	t_vt_lst *new;

	new = (t_vt_lst *)malloc(sizeof(t_vt_lst));	
	if (!new)
	{
		printf("malloc error\n");
		exit (-1);
	}
	if ((sscanf(line, "vt %f %f", &new->u, &new->v)) != 2)
		printf("sscanfn error\n");
	new->next = NULL;
	return (new);
}

t_v_lst 	*parse_vec_line(const char *line)
{
	t_v_lst *new;

	new = (t_v_lst *)malloc(sizeof(t_v_lst));
	if (!new)
	{
		printf("malloc error\n");
		exit (-1);
	}
	if ((sscanf(line, "v %f %f %f", &new->pos.x, &new->pos.y, &new->pos.z)) != 3)
		printf("sscanfn error\n");
	new->next = NULL;
	return (new);
}

t_f_lst 	*parse_face_line_textured(const char *line)
{
	t_f_lst *new;
	int i_nb;

	new = (t_f_lst *)malloc(sizeof(t_f_lst));	
	if (!new)
	{
		printf("malloc error\n");
		exit (-1);
	}
	i_nb = sscanf(line, "f %d/%d %d/%d %d/%d %d/%d", &new->indices[0], 
		&new->tex_cords[0], &new->indices[1], &new->tex_cords[1], 
		&new->indices[2], &new->tex_cords[2], &new->indices[3], 
		&new->tex_cords[3]);
	if (i_nb != 6 && i_nb != 8)
	{
		printf("parsing error: weird number of indices\n");
		exit(-1);
	}
	new->nb = i_nb * 0.5;
	new->next = NULL;
	return (new);
}

t_f_lst 	*parse_face_line(const char *line)
{
	t_f_lst 	*new;
	int 		i_nb;

	new = (t_f_lst *)malloc(sizeof(t_f_lst));	
	if (!new)
	{
		printf("malloc error\n");
		exit (-1);
	}
	i_nb = sscanf(line, "f %d %d %d %d", &new->indices[0], &new->indices[1], &new->indices[2], &new->indices[3]);
	if (i_nb < 3)
	{
		printf("parsing error: weird number of indices\n");
		exit(-1);
	}
	new->nb = i_nb;
	new->next = NULL;
	return (new);
}

static void new_parser(int fd, t_env *e)
{
	t_v_lst  *v_it = NULL;
	t_f_lst *f_it = NULL;
	t_vt_lst *vt_it = NULL;


	e->v_lst = (t_v_lst *)malloc(sizeof(t_v_lst));	
	if (!e->v_lst)
	{
		printf("malloc error\n");
		exit (-1);
	}
	e->f_lst = (t_f_lst *)malloc(sizeof(t_f_lst));	
	if (!e->f_lst)
	{
		printf("malloc error\n");
		exit (-1);
	}
	e->vt_lst = (t_vt_lst *)malloc(sizeof(t_vt_lst));	
	if (!e->vt_lst)
	{
		printf("malloc error\n");
		exit (-1);
	}
	v_it = e->v_lst;
	f_it = e->f_lst;
	vt_it = e->vt_lst;

    char    *line;
	int     v_nb;
	int     vt_nb;
	int     i_nb;

	v_nb = 0;
	vt_nb = 0;
	i_nb = 0;
    while ((get_next_line(fd, &line)) > 0)
	{
        if (line && !ft_strncmp(line, "v ", 2))
		{
			v_nb++;
			v_it->next = parse_vec_line(line);
			v_it = v_it->next;
		}
		else if (line && !ft_strncmp(line, "vt ", 3))
		{
			e->mesh.textured = true;
			vt_nb++;
			vt_it->next = parse_vt_line(line);
			vt_it = vt_it->next;
		}
		else if (line && !ft_strncmp(line, "f ", 2))
		{
			if ((ft_strchr_sec(line, '/')))
			{
				e->mesh.textured = true;
				f_it->next = parse_face_line_textured(line);
			}
			else 
				f_it->next = parse_face_line(line);
			f_it = f_it->next;
			i_nb += f_it->nb;
			//printf("%s\n", line);
		}
        (line) ? ft_strdel(&line) : 0;
	}
    (line) ? ft_strdel(&line) : 0;

	e->data_size.v_nb = v_nb;
	e->data_size.vt_nb = vt_nb;
	e->data_size.indice_nb = i_nb;
}

void 	get_min_max(t_env *e)
{
	unsigned int i;

	i = 0;
	e->data_size.min.x = e->mesh.verts[i].pos.x;
	e->data_size.max.x = e->mesh.verts[i].pos.x;
	e->data_size.min.y = e->mesh.verts[i].pos.y;
	e->data_size.max.y = e->mesh.verts[i].pos.y;
	e->data_size.min.z = e->mesh.verts[i].pos.z;
	e->data_size.max.z = e->mesh.verts[i].pos.z;
	while (i < e->data_size.v_nb)
	{
		if (e->mesh.verts[i].pos.x < e->data_size.min.x)
			e->data_size.min.x = e->mesh.verts[i].pos.x;
		else if (e->mesh.verts[i].pos.x > e->data_size.max.x)
			e->data_size.max.x = e->mesh.verts[i].pos.x;
		if (e->mesh.verts[i].pos.y < e->data_size.min.y)
			e->data_size.min.y = e->mesh.verts[i].pos.y;
		else if (e->mesh.verts[i].pos.y > e->data_size.max.y)
			e->data_size.max.y = e->mesh.verts[i].pos.y;
		if (e->mesh.verts[i].pos.z < e->data_size.min.z)
			e->data_size.min.z = e->mesh.verts[i].pos.z;
		else if (e->mesh.verts[i].pos.z > e->data_size.max.z)
			e->data_size.max.z = e->mesh.verts[i].pos.z;
		i++;
	}
}

bool    parse_file(char *file_name, t_env *e)
{
    int     fd;

    if ((fd = open(file_name, O_DIRECTORY)) >= 0)
        return (false);
    if ((fd = open(file_name, O_RDONLY)) < 0) {
        return (false);
	}
	new_parser(fd, e);
	malloc_buffers(e);
	process_data(e);
	//process_vdata(e);
	//process_data(e);
	//process_fdata(e);
	free_lists(e);

	get_min_max(e);

    return (true);
}
