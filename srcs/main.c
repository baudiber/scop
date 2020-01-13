#include "../includes/scop.h"

int     main(int ac, char **av)
{
    if (ac != 2 || ft_strequ("", av[1]))
    {
        ft_putendl("usage : ./scop file.obj");
		return (0);
    }

    ft_putstr("Opening ");
    ft_putendl(av[1]);
    if (!parse_file(av[1]))
    {
        ft_putendl("ERROR parsing file");
		return (0);
    }
    //run();
    return (0);
}