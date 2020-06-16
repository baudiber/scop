#include "../../includes/scop.h"

// # for comments
// v  for vectors               followed by x y z w                      w is optional and will default to 1.0
// vp for free-form geometry
// mtllib <.mtl file>
// o object
// usemtl <material name>
// s on/off
// f  for faces   followed by vectex by index (starting at 1)

static void check_data(int fd, t_size *data)
{
    char    *line;
    int     rd;
    unsigned int     faces;
    unsigned int     vecs;
	char 	**v_data;
	char 	**f_data;

    faces = 0;
    vecs = 0;
    while ((rd = get_next_line(fd, &line)) > 0)
    {
        if (line && line[0] == 'v')
		{
			v_data = ft_strsplit(line, ' ');
            vecs += ft_tablen(v_data) - 1;
			ft_freetab(v_data);
		}
        else if (line && line[0] == 'f')
		{
			f_data = ft_strsplit(line, ' ');
            faces += ft_tablen(f_data) - 1;
			ft_freetab(f_data);
		}
        (line) ? ft_strdel(&line) : 0;
    }
    (line) ? ft_strdel(&line) : 0;

	data->f_nb = faces;
	data->v_nb = vecs;
    ft_putchar('v');
    ft_putnbr(vecs);
    ft_putchar(' ');
    ft_putchar('f');
    ft_putnbr(faces);
    ft_putchar('\n');
}

//static float *parse_v_data(char ***data, int size)
//{
//	float * vertices;
//
//	if (!(vertices = (float*)malloc(sizeof(float) * size)))
//	{
//		ft_putendl("malloc error vdata");
//		exit(0);
//	}
//}
//
//static int *parse_f_data(char ***data, int size)
//{
//	int *indices;
//
//	if (!(indices = (int*)malloc(sizeof(int) * size)))
//	{
//		ft_putendl("malloc error fdata");
//		exit(0);
//	}
//}
//

static void get_data(int fd, t_size *data)
{
    char    *line;
    int     rd;
	char 	**v_data;
	char 	**f_data;
//	float 	*vertices;
//	unsigned int *indices;

    while ((rd = get_next_line(fd, &line)) > 0)
    {
        if (line && line[0] == 'v')
		{
			v_data = ft_strsplit(line, ' ');
		}
        if (line && line[0] == 'f')
		{
			 f_data = ft_strsplit(line, ' ');
		}
        (line) ? ft_strdel(&line) : 0;
    }
    (line) ? ft_strdel(&line) : 0;

//	vertices = parse_v_data(v_data, data->v_nb);
//	indices = parse_f_data(f_data, data->f_nb);
}

void 	malloc_data(t_size *data)
{

}

bool    parse_file(char *file_name)
{
    int     fd;
	t_size 	data;

    if ((fd = open(file_name, O_DIRECTORY)) >= 0)
        return (false);
    if ((fd = open(file_name, O_RDONLY)) < 0)
        return (false);
    check_data(fd, &data);
	malloc_data(&data);
	
	if ((fd = close(fd)) < 0) 
		return (false);
    if ((fd = open(file_name, O_RDONLY)) < 0)
       return (false);
	get_data(fd, &data);

    return (true);
}
