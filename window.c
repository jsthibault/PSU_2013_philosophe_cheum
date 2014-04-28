/*
** window.c for philosophes in /home/loic/dev/epitech/c/philosophes
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  sam. mars 22 17:38:30 2014 lefloc_l
** Last update dim. mars 23 19:12:40 2014 lefloc_l
*/

#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include "Window.h"

static void	init_surfaces(SDL_Surface **eat, SDL_Surface **sleep,
    SDL_Surface **think)
{
  if (NULL == (*eat = IMG_Load("./img/eat1.jpg")))
    mexit(IMG_GetError());
  if (NULL == (*sleep = IMG_Load("./img/sleep1.png")))
    mexit(IMG_GetError());
  if (NULL == (*think = IMG_Load("./img/think1.jpg")))
    mexit(IMG_GetError());
}

static void	fill_win(SDL_Surface *screen, unsigned long start)
{
  SDL_Surface	*eat;
  SDL_Surface	*sleep;
  SDL_Surface	*think;
  SDL_Event	event;

  init_surfaces(&eat, &sleep, &think);
  while (1)
  {
    if (1 == SDL_PollEvent(&event))
      if (event.type == SDL_QUIT)
        return ;
    if (!isTimeout(start, 1))
    {
      SDL_FillRect(screen, NULL, 0xffffff);
      start = clock();
      place_philosophes(screen, eat, sleep, think);
      place_text(screen);
      if (-1 == SDL_Flip(screen))
        mexit("SDL_Flip error");
    }
  }
  SDL_FreeSurface(think);
  SDL_FreeSurface(sleep);
  SDL_FreeSurface(eat);
}

static void	create_window()
{
  SDL_Surface	*screen;

  screen = NULL;
  if (NULL == (screen = SDL_SetVideoMode(W_WIDTH, W_HEIGHT, 32,
          SDL_HWSURFACE | SDL_DOUBLEBUF)))
    mexit(SDL_GetError());
  SDL_WM_SetCaption(W_TITLE, NULL);
  fill_win(screen, clock() + 10000);
  SDL_Quit();
  TTF_Quit();
}

void	*run_sdl()
{
  if (-1 == SDL_Init(SDL_INIT_VIDEO))
    mexit(SDL_GetError());
  if (-1 == TTF_Init())
    mexit(TTF_GetError());
  create_window();
  return NULL;
}

pthread_t	launch_sdl()
{
  pthread_t	thread;

  if (-1 == pthread_create(&thread, NULL, run_sdl, NULL))
  {
    fprintf(stderr, "Pthread_create failed.\n");
    exit (1);
  }
  return (thread);
}
