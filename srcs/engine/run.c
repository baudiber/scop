#include "../../includes/scop.h"

void run(void)
{
    t_env *e;
    SDL_Event event;

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    while (true)
    {
        e = get_env();
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT || (event.key.keysym.sym == SDLK_ESCAPE && event.type == SDL_KEYDOWN))
                exit(0);

            glClear(GL_COLOR_BUFFER_BIT);



            SDL_GL_SwapWindow(e->win);
        }
    }
}