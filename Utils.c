/*
** Utils.c for etape_1 in /home/loic/dev/epitech/c/rush/etape_1
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  ven. mars 07 20:53:13 2014 lefloc_l
** Last update Sun Mar 23 19:00:59 2014 thibau_j
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	mexit(char *str)
{
  fprintf(stderr, "%s\n", str);
  exit(EXIT_FAILURE);
}

int	isTimeout(unsigned long begin_time, unsigned long sec)
{
  return (sec >= ((unsigned long) clock() - begin_time) / CLOCKS_PER_SEC);
}
