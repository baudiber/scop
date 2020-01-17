#include "../includes/scop.h"

t_env   *get_env(void) {
    static t_env    e;

    return (&e);
}

int     main(int ac, char **av)
{
    t_env   *e;

    if (ac != 2 || ft_strequ("", av[1]))
    {
        ft_putendl("usage : ./scop file.obj");
		return (0);
    }

    e = get_env();
    ft_putstr("Opening ");
    ft_putendl(av[1]);
    if (!parse_file(av[1]))
    {
        ft_putendl("ERROR parsing file");
		return (0);
    }
    if (!init())
    {
        ft_putendl("ERROR during init");
        return (-1);
    }

    ft_putendl("lol");
    run();
    return (0);
}