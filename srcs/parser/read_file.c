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

static void check_data(int fd, t_size *data_size)
{
    char    *line;
    int     rd;
    unsigned int     faces;
    unsigned int     vecs;
	unsigned int 		indices;
	unsigned int 	points;
	char 	**data;

    faces = 0;
    vecs = 0;
	indices = 0;
	points = 0;
    while ((rd = get_next_line(fd, &line)) > 0)
    {
        if (line && line[0] == 'v')
		{
			vecs++;
			data = ft_strsplit(line, ' ');
            points += ft_tablen(data) - 1;
			ft_freetab(data);
		}
        else if (line && line[0] == 'f')
		{
			data = ft_strsplit(line, ' ');
            indices += ft_tablen(data) - 1;
			ft_freetab(data);
			faces++;
		}
        (line) ? ft_strdel(&line) : 0;
    }
    (line) ? ft_strdel(&line) : 0;

	data_size->f_nb = faces;
	data_size->v_nb = vecs;
	data_size->indices = indices;
	data_size->points = points;
    ft_putchar('v');
    ft_putnbr(vecs);
    ft_putchar(' ');
    ft_putchar('f');
    ft_putnbr(faces);
    ft_putchar('\n');
}

static void parse_v_data(char ***data_ptr, t_vec3 *verts)
{
	char	**data = *data_ptr;
	int		tablen;

	tablen = ft_tablen(data);
	if (tablen != 4)
	{
		ft_putendl("error parsing OBJ's vecs");
		exit (0);
	}

	verts->x = ft_atod(data[1]) / 4;
	verts->y = ft_atod(data[2]) / 4;
	verts->z = ft_atod(data[3]) / 4 - 0.5;
	//printf("%f %f %f\n", verts->x, verts->y, verts->z);
}

static void fill_points(char ***data_ptr, float **verts, int *index)
{
	char	**data = *data_ptr;
	int		tablen;

	tablen = ft_tablen(data);
	if (tablen != 4)
	{
		ft_putendl("error parsing OBJ's vecs");
		exit (0);
	}
	(*verts)[*index] = ft_atod(data[1]) / 4;
	(*verts)[(*index) + 1] = ft_atod(data[2]) / 4;
	(*verts)[(*index) + 2] = ft_atod(data[3]) / 4 + 0.5;
	(*index) += 3;
}

static void parse_f_data(char ***data_ptr, int **face)
{
	char 	**data = *data_ptr;
	int 	i;
	int 	tablen;

	tablen = ft_tablen(data);
	if (tablen < 4)
	{
		ft_putendl("error parsing OBJ's face (size < 4)");
		exit (0);
	}
	if (!(*face = (int *)malloc(sizeof(int) * tablen - 1)))
		exit(0);
	i = 0;
	while (i < tablen - 1)
	{
		(*face)[i] = ft_atoi(data[i + 1]);
		i++;
	}
}

static void fill_indices(char ***data_ptr, unsigned int **indices, int *index)
{
	char 	**data = *data_ptr;
	int 	i;
	int 	tablen;

	tablen = ft_tablen(data);
	if (tablen < 4)
	{
		ft_putendl("error parsing OBJ's face (size < 3)");
		exit (0);
	}
	i = 1;
	while (i < tablen)
	{
		(*indices)[(*index)] = ft_atoi(data[i]);
		++(*index);
		i++;
	}
}

static void get_data(int fd, t_mesh *mesh)
{
    char    *line;
    int     rd;
	int 	vec;
	int 	face;
	char 	**data;
	int 	indice_index;
	int 	vert_index;

	vec = 0;
	face = 0;
	indice_index = 0;
	vert_index = 0;
	while ((rd = get_next_line(fd, &line)) > 0)
	{
		if (line && line[0] == 'v')
		{
			data = ft_strsplit(line, ' ');
			parse_v_data(&data, &mesh->vertices[vec]);
			fill_points(&data, &mesh->verts, &vert_index);
			ft_freetab(data);
			vec++;
		}
		if (line && line[0] == 'f')
		{
			data = ft_strsplit(line, ' ');
			parse_f_data(&data, &mesh->faces[face]);
			fill_indices(&data, &mesh->indices, &indice_index);
			ft_freetab(data);
			face++;
		}
		(line) ? ft_strdel(&line) : 0;
	}
	(line) ? ft_strdel(&line) : 0;
}

void 	malloc_data(t_size *data_size, t_mesh *mesh)
{
	if (!(mesh->vertices = (t_vec3 *)malloc(sizeof(t_vec3) * data_size->v_nb)))
		exit(0);
	if (!(mesh->verts = (float *)malloc(sizeof(float) * data_size->points)))
		exit(0);
	if (!(mesh->faces = (int **)malloc(sizeof(int *) * data_size->f_nb)))
		exit(0);
	ft_putnbr(data_size->indices);
	if (!(mesh->indices = (unsigned int *)malloc(sizeof(int) * data_size->indices)))
		exit(0);
}

bool    parse_file(char *file_name, t_env *e)
{
    int     fd;

    if ((fd = open(file_name, O_DIRECTORY)) >= 0)
        return (false);
    if ((fd = open(file_name, O_RDONLY)) < 0)
        return (false);
    check_data(fd, &e->data_size);
	malloc_data(&e->data_size, &e->mesh);
	
	if ((fd = close(fd)) < 0) 
		return (false);
    if ((fd = open(file_name, O_RDONLY)) < 0)
       return (false);
	get_data(fd, &e->mesh);

    return (true);
}
