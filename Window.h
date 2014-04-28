/*
** Window.h for philosophes in /home/loic/dev/epitech/c/philosophes
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  sam. mars 22 17:49:14 2014 lefloc_l
** Last update dim. mars 23 02:12:43 2014 lefloc_l
*/

#ifndef WINDOW_H_
# define WINDOW_H_

# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <SDL/SDL_ttf.h>

# define W_WIDTH	1300
# define W_HEIGHT	800
# define W_TITLE	"Philosophes"
# define CASE		250

pthread_t		launch_sdl();
int			isTimeout(unsigned int, unsigned int);
void			mexit(char *str);
void			place_text(SDL_Surface *screen);
void		place_philosophes(SDL_Surface *screen,
    SDL_Surface *eat,
    SDL_Surface *sleep,
    SDL_Surface	*think);

#endif /* !WINDOW_H_ */
