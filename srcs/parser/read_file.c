#include "../../includes/scop.h"

// # for comments
// v  for vectors               followed by x y z w                      w is optional and will default to 1.0
// vp for free-form geometry
// mtllib <.mtl file>
// o object
// usemtl <material name>
// s on/off
// f  for faces   followed by vectex by index (starting at 1)

void    get_data(int fd)
{
    char    *line;
    int     rd;
    unsigned int     faces;
    unsigned int     vecs;

    faces = 0;
    vecs = 0;
    while ((rd = get_next_line(fd, &line)) > 0)
    {
        if (line && line[0] == 'f')
            faces++;
        if (line && line[0] == 'v')
            vecs++;
        (line) ? ft_strdel(&line) : 0;
    }
    (line) ? ft_strdel(&line) : 0;

    ft_putnbr(faces);
    ft_putchar(' ');
    ft_putnbr(vecs);
    ft_putchar('\n');
}

bool    parse_file(char *file_name)
{
    int     fd;

    if ((fd = open(file_name, O_DIRECTORY)) >= 0)
        return (false);
    if ((fd = open(file_name, O_RDONLY)) < 0)
        return (false);
    get_data(fd);
    return (true);
}