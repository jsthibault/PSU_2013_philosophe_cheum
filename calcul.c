/*
** calcul.c for philosophes in /home/loic/dev/epitech/c/philosophes
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  sam. mars 22 18:02:20 2014 lefloc_l
** Last update dim. mars 23 19:21:22 2014 lefloc_l
*/

#include "./Window.h"
#include "./philo.h"

extern int	g_philos[7];

static SDL_Rect	getPlacement(size_t i)
{
  SDL_Rect	pos;

  if (i < 3)
    pos.x = 100;
  if (i >= 3 && i < 6)
  {
    i -= 3;
    pos.x = 100 + CASE * 2;
  }
  pos.y = 50 + (CASE * (i));
  if (i == 6)
  {
    pos.x = 100 + CASE;
    pos.y = (CASE * 2) + 50;
  }
  return pos;
}

static SDL_Surface	*getCurrent(size_t i, SDL_Surface *eat,
    SDL_Surface *sleep,
    SDL_Surface *think)
{
  if (g_philos[i] == EAT)
    return eat;
  else if (g_philos[i] == SLEEP)
    return sleep;
  else if (g_philos[i] == THINK)
    return think;
  return NULL;
}

void		place_philosophes(SDL_Surface *screen,
    SDL_Surface *eat,
    SDL_Surface *sleep,
    SDL_Surface	*think)
{
  SDL_Rect		pos;
  size_t		i;

  i = 0;
  while (i < 7)
  {
    pos = getPlacement(i);
    if (-1 == SDL_BlitSurface(getCurrent(i, eat, sleep, think),
          NULL, screen, &pos))
      mexit("SDL_BlitSurface error.");
    ++i;
  }
}

