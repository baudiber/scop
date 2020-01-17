#ifndef SCOP_H
# define SCOP_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include "SDL.h"
# include "../includes/glad/glad.h"
//#include <GL/gl.h>

# define WIN_W 1024
# define WIN_H 768

typedef struct s_env    t_env;

struct s_env
{
    SDL_Window      *win;
    SDL_Surface     *screen;
    Uint32          *buffer;
    SDL_GLContext   *context;
    const Uint8		*state;
};

t_env   *get_env(void);
bool    parse_file(char *file_name);
bool    init(void);
void    run(void);

#endif