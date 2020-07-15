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

void 		malloc_buffers(t_env *e)
{
	if (!(e->data.v = (t_vec3 *)malloc(sizeof(t_vec3) * e->data_size.v_nb)))
	{
		printf("malloc error");
		exit(-1);
	}
	if (!(e->data.indices = (t_vec2_int *)malloc(sizeof(t_vec2_int) * e->data_size.indice_nb)))
	{
		printf("malloc error");
		exit(-1);
	}
	if (e->mesh.textured)
	{
		if (!(e->data.vt = (t_vec2 *)malloc(sizeof(t_vec2) * e->data_size.vt_nb)))
		{
			printf("malloc error");
			exit(-1);
		}
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
	if ((sscanf(line, "vt %f %f", &new->uv.x, &new->uv.y)) != 2)
	{
		printf("sscanfn error\n");
		exit(-1);
	}
	new->next = NULL;
	return (new);
}

t_v_lst 	*parse_v_line(const char *line)
{
	t_v_lst *new;

	new = (t_v_lst *)malloc(sizeof(t_v_lst));
	if (!new)
	{
		printf("malloc error\n");
		exit (-1);
	}
	if ((sscanf(line, "v %f %f %f", &new->pos.x, &new->pos.y, &new->pos.z)) != 3)
	{
		printf("sscanfn error\n");
		exit(-1);
	}
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
			v_it->next = parse_v_line(line);
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
		}
        (line) ? ft_strdel(&line) : 0;
	}
    (line) ? ft_strdel(&line) : 0;

	e->data_size.indice_nb = i_nb;
	e->data_size.v_nb = v_nb;
	e->data_size.vt_nb = vt_nb;
	e->data_size.vt_nb = vt_nb;
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
	printf("textured: %d vnb: %d vtnb: %d indexnb: %d\n", e->mesh.textured, e->data_size.v_nb, e->data_size.vt_nb, e->data_size.indice_nb);
    return (true);
}
