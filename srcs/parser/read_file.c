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

static void new_parser(int fd, t_env *e)
{
    int     rd;
    char    *line;

	(void)e;
    while ((rd = get_next_line(fd, &line)) > 0)
	{
        //if (line && !ft_strncmp(line, "v ", 2))
		//{
		//	printf("%s\n", line);
		//}
		//else if (line && !ft_strncmp(line, "f ", 2))
		//{
		//	printf("%s\n", line);
		//}
        (line) ? ft_strdel(&line) : 0;
	}
    (line) ? ft_strdel(&line) : 0;
}

//static void check_data(int fd, t_size *data_size)
//{
//    char    *line;
//    int     rd;
//    unsigned int     faces;
//    unsigned int     vecs;
//	unsigned int 		indices;
//	unsigned int 	points;
//	unsigned int 	face;
//	char 	**data;
//
//    faces = 0;
//    vecs = 0;
//	indices = 0;
//	points = 0;
//	face = 0;
//    while ((rd = get_next_line(fd, &line)) > 0)
//    {
//        if (line && line[0] == 'v')
//		{
//			vecs++;
//			data = ft_strsplit(line, ' ');
//            points += ft_tablen(data) - 1;
//			ft_freetab(data);
//		}
//        else if (line && line[0] == 'f')
//		{
//			data = ft_strsplit(line, ' ');
//			face = ft_tablen(data) - 1;
//			if (face == 3) 
//            	indices += 3;
//			else if (face == 4)
//				indices += 6;
//			ft_freetab(data);
//			faces++;
//		}
//        (line) ? ft_strdel(&line) : 0;
//    }
//    (line) ? ft_strdel(&line) : 0;
//
//	data_size->f_nb = faces;
//	data_size->v_nb = vecs;
//	data_size->indices = indices;
//	data_size->points = points;
//   // ft_putchar('v');
//   // ft_putnbr(vecs);
//   // ft_putchar(' ');
//   // ft_putchar('f');
//   // ft_putnbr(faces);
//   // ft_putchar('\n');
//}
//
//static void parse_v_data(char ***data_ptr, t_vec3 *verts)
//{
//	char	**data = *data_ptr;
//	char 	** split;
//	int		tablen;
//
//	tablen = ft_tablen(data);
//	if (tablen != 4)
//	{
//		ft_putendl("error parsing OBJ's vecs");
//		exit (0);
//	}
//	// v 1/2 3/4 4/5
//
//	split = ft_strsplit(data[1], '/');
//	if (ft_tablen(split) == 2)
//	{
//		verts->x = atof(split[0]);
//	}
//
//
//
//	verts->x = atof(data[1]);
//
//
////	printf("%s %f %f \n",data[1], verts->x, atof(data[1]));
//	verts->y = atof(data[2]);
////	printf("%s %f %f \n", data[2],verts->y, atof(data[2]));
//	verts->z = atof(data[3]);
////	printf("%s %f %f \n", data[3], verts->z, atof(data[3]));
//	//printf("%f %f %f\n", verts->x, verts->y, verts->z);
//}
//
//static void parse_f_data(char ***data_ptr, int **face)
//{
//	char 	**data = *data_ptr;
//	int 	i;
//	int 	tablen;
//
//	tablen = ft_tablen(data);
//	if (tablen < 4)
//	{
//		ft_putendl("error parsing OBJ's face (size < 4)");
//		exit (0);
//	}
//	if (!(*face = (int *)malloc(sizeof(int) * tablen - 1)))
//		exit(0);
//	i = 0;
//	while (i < tablen - 1)
//	{
//		(*face)[i] = ft_atoi(data[i + 1]) ;
//		i++;
//	}
//}
//
//static void fill_indices(char ***data_ptr, unsigned int **indices, int *index)
//{
//	char 	**data = *data_ptr;
//	int 	i;
//	int 	tablen;
//
//	tablen = ft_tablen(data);
//	if (tablen < 4)
//	{
//		ft_putendl("error parsing OBJ's face (size < 3)");
//		exit (0);
//	}
//
//	if (tablen == 4) // triangle
//	{
//		i = 1;
//		while (i < tablen)
//		{
//			(*indices)[(*index)] = ft_atoi(data[i]) - 1;
//			++(*index);
//			i++;
//		}
//	}
//	else if (tablen == 5) // quad
//	{
//		(*indices)[(*index)] = ft_atoi(data[1]) - 1;
//		++(*index);
//		(*indices)[(*index)] = ft_atoi(data[2]) - 1;
//		++(*index);
//		(*indices)[(*index)] = ft_atoi(data[3]) - 1;
//		++(*index);
//		(*indices)[(*index)] = ft_atoi(data[3]) - 1;
//		++(*index);
//		(*indices)[(*index)] = ft_atoi(data[4]) - 1;
//		++(*index);
//		(*indices)[(*index)] = ft_atoi(data[1]) - 1;
//		++(*index);
//	}
//}
//
//static void get_data(int fd, t_mesh *mesh)
//{
//    char    *line;
//    int     rd;
//	int 	vec;
//	int 	face;
//	char 	**data;
//	int 	indice_index;
//	int 	vert_index;
//
//	vec = 0;
//	face = 0;
//	indice_index = 0;
//	vert_index = 0;
//	while ((rd = get_next_line(fd, &line)) > 0)
//	{
//		if (line && line[0] == 'v')
//		{
//			data = ft_strsplit(line, ' ');
//			parse_v_data(&data, &mesh->vertices[vec].pos);
//			ft_freetab(data);
//			vec++;
//		}
//		if (line && line[0] == 'f')
//		{
//			data = ft_strsplit(line, ' ');
//			parse_f_data(&data, &mesh->faces[face]);
//			fill_indices(&data, &mesh->indices, &indice_index);
//			ft_freetab(data);
//			face++;
//		}
//		(line) ? ft_strdel(&line) : 0;
//	}
//	(line) ? ft_strdel(&line) : 0;
//}
//
//void 	malloc_data(t_size *data_size, t_mesh *mesh)
//{
//	if (!(mesh->vertices = (t_vertex *)malloc(sizeof(t_vertex) * data_size->v_nb)))
//		exit(0);
//	if (!(mesh->verts = (float *)malloc(sizeof(float) * data_size->points)))
//		exit(0);
//	if (!(mesh->faces = (int **)malloc(sizeof(int *) * data_size->f_nb)))
//		exit(0);
//	//ft_putnbr(data_size->indices);
//	if (!(mesh->indices = (unsigned int *)malloc(sizeof(int) * data_size->indices)))
//		exit(0);
//}

//void 	get_min_max(t_env *e)
//{
//	unsigned int i;
//
//	i = 0;
//	e->data_size.min.x = e->mesh.vertices[i].pos.x;
//	e->data_size.max.x = e->mesh.vertices[i].pos.x;
//	e->data_size.min.y = e->mesh.vertices[i].pos.y;
//	e->data_size.max.y = e->mesh.vertices[i].pos.y;
//	e->data_size.min.z = e->mesh.vertices[i].pos.z;
//	e->data_size.max.z = e->mesh.vertices[i].pos.z;
//	while (i < e->data_size.v_nb)
//	{
//		if (e->mesh.vertices[i].pos.x < e->data_size.min.x)
//			e->data_size.min.x = e->mesh.vertices[i].pos.x;
//		else if (e->mesh.vertices[i].pos.x > e->data_size.max.x)
//			e->data_size.max.x = e->mesh.vertices[i].pos.x;
//		if (e->mesh.vertices[i].pos.y < e->data_size.min.y)
//			e->data_size.min.y = e->mesh.vertices[i].pos.y;
//		else if (e->mesh.vertices[i].pos.y > e->data_size.max.y)
//			e->data_size.max.y = e->mesh.vertices[i].pos.y;
//		if (e->mesh.vertices[i].pos.z < e->data_size.min.z)
//			e->data_size.min.z = e->mesh.vertices[i].pos.z;
//		else if (e->mesh.vertices[i].pos.z > e->data_size.max.z)
//			e->data_size.max.z = e->mesh.vertices[i].pos.z;
//		i++;
//	}
//}

bool    parse_file(char *file_name, t_env *e)
{
    int     fd;

    if ((fd = open(file_name, O_DIRECTORY)) >= 0)
        return (false);
    if ((fd = open(file_name, O_RDONLY)) < 0) {
        return (false);
	}
	new_parser(fd, e);
    //check_data(fd, &e->data_size);
	//malloc_data(&e->data_size, &e->mesh);
	
	//if ((fd = close(fd)) < 0) 
	//	return (false);
    //if ((fd = open(file_name, O_RDONLY)) < 0)
    //   return (false);
	//get_data(fd, &e->mesh);
	
//	get_min_max(e);

    return (true);
}
