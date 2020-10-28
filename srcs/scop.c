#include <scop.h>

void 	clean_exit(const char *msg)
{
	printf("%s", msg);
	//free_lists?
	//opengl exit?
	glfwTerminate();
	exit(1);
}

t_env					*get_env(void)
{
	static t_env		e;

	return (&e);
}

void print_man()
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~ SCOP ~~~~~~~~~~~~~\n");
	printf("Commands: \n");
	printf("WS to zoom\n");
	printf("ARROWS for movement\n");
	printf("C F T to switch shading modes\n");
	printf("ESC to quit\n");
	printf(". for WIREFRAME view\n");
	printf("/ for VERTEX view\n");
	printf(", revert to FILLED view\n");
	printf("+- switch between textures(2)\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	printf("Some shading and texturing options will not work unless\n");
	printf("the obj has texture or normal coordinates.\n");
	printf("\n");
}

void scop(char *av1)
{
    t_env   *e;

	e = get_env();
	ft_bzero(e, sizeof(t_env));

	print_man();
    ft_putstr("Opening ");
    ft_putendl(av1);
	parse_obj(av1, e);
	parse_shaders(e);
    if (!init(e))
    {
        ft_putendl("ERROR during init");
        return;
    }
    run(e);
	glfwTerminate();
}
