/*
** text.c for philosophes in /home/loic/dev/epitech/c/philosophes
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  sam. mars 22 21:16:08 2014 lefloc_l
** Last update dim. mars 23 01:49:48 2014 lefloc_l
*/

#include "./Window.h"
#include "./philo.h"

extern int	g_philos[7];

static char	*get_current_status(size_t i)
{
  if (g_philos[i] == SLEEP)
    return "sleep";
  else if (g_philos[i] == EAT)
    return "eat";
  else if (g_philos[i] == THINK)
    return "think";
  return "ERROR";
}

static void		set_text(SDL_Surface *screen, SDL_Color color,
    SDL_Rect pos, TTF_Font *font)
{
  char			*str;
  size_t		i;
  SDL_Surface		*text;

  i = 0;
  if (!(str = malloc(500)))
    mexit("Malloc failed.");
  pos.x += 80;
  while (i < 7)
  {
    sprintf(str, "Philosphe %ld:     %s", i + 1, get_current_status(i));
    pos.y += 35;
    if (!(text = TTF_RenderText_Blended(font, str, color)))
      mexit("Text error.");
    if (-1 == SDL_BlitSurface(text, NULL, screen, &pos))
      mexit("SDL_BlitSurface error");
    SDL_FreeSurface(text);
    ++i;
  }
  free(str);
}

static void		set_header(SDL_Surface *screen, SDL_Color color,
    SDL_Rect pos, TTF_Font *font)
{
  char			*str;
  SDL_Surface		*text;

  if (!(str = malloc(500)))
    mexit("Malloc failed.");
  sprintf(str, "=============================");
  if (!(text = TTF_RenderText_Blended(font, str, color)))
    mexit("Text error.");
  if (-1 == SDL_BlitSurface(text, NULL, screen, &pos))
    mexit("SDL_BlitSurface error");
  SDL_FreeSurface(text);
  free(str);
}

void		set_table(SDL_Surface *screen)
{
  SDL_Surface	*table;
  SDL_Rect	pos;

  if (NULL == (table = IMG_Load("./img/table1.png")))
    mexit(IMG_GetError());
  pos.x = 210;
  pos.y = 5;
  if (-1 == SDL_BlitSurface(table, NULL, screen, &pos))
      mexit("SDL_BlitSurface error.");
  SDL_FreeSurface(table);
}

void		place_text(SDL_Surface *screen)
{
  TTF_Font	*font;
  SDL_Color	color;
  SDL_Rect	pos;

  color.r = 50;
  color.g = 227;
  color.b = 53;
  color.b = 0;
  pos.x = 850;
  pos.y = 100;
  if (!(font = TTF_OpenFont("cl.ttf", 20)))
    mexit("Couldn't load font");
  set_header(screen, color, pos, font);
  set_text(screen, color, pos, font);
  pos.y += 35 * 8;
  set_header(screen, color, pos, font);
  set_table(screen);
}
