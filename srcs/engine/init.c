#include "../../includes/scop.h"
#include <stdio.h>

bool init(void)
{
    t_env *e;

    e = get_env();

    if ((SDL_Init(SDL_INIT_VIDEO)) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return (false);
    }

    if ((SDL_GL_LoadLibrary(NULL)) != 0)
    {
        SDL_Log("Unable to initialize OPENGL: %s", SDL_GetError());
        return (false);
    }
    // Request an OpenGL 4.5 context (should be core)
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    // Also request a depth buffer
    //SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 0);
    //SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 0);

     if (!(e->win = SDL_CreateWindow("scop", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_W, WIN_H, SDL_WINDOW_OPENGL)))
        return (false);

    printf("Version:  %s\n", glGetString(GL_VERSION));
    SDL_GLContext test;
    //if(!(e->context = SDL_GL_CreateContext(e->win)))
    if(!(test = SDL_GL_CreateContext(e->win)))
    {
        SDL_Log("Unable to initialize OPENGL: %s", SDL_GetError());
        return (false);
    }

    gladLoadGLLoader(SDL_GL_GetProcAddress);
    glViewport(0, 0, WIN_W, WIN_H);


    return (true);
}