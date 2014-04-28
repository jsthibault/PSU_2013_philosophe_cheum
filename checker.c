/*
** checker.c for checker.c in /home/thibauj/rendu/philosophes
**
** Made by thibau_j
** Login   <thibau_j@epitech.net>
**
** Started on  Sat Mar 22 14:02:37 2014 thibau_j
** Last update Sun Mar 23 19:02:52 2014 thibau_j
*/

#include <stdio.h>
#include "philo.h"

extern int	g_philos[7];

t_bool		sticks_free(t_stick *ptr, int i)
{
  int		next_stick;

  next_stick = (i + 1) % PHILO;
  if (ptr->free_stick[i] != 0 && ptr->free_stick[next_stick] != 0)
    return (TRUE);
  return (FALSE);
}

void		take_stick(t_stick *ptr, int i)
{
  int		next_stick;

  next_stick = (i + 1) % PHILO;
  ptr->free_stick[next_stick] = FALSE;
  ptr->free_stick[i] = ptr->free_stick[next_stick];
}

void		freesticks(t_stick *ptr, int i)
{
  int		next_stick;

  next_stick = (i + 1) % PHILO;
  ptr->free_stick[next_stick] = TRUE;
  ptr->free_stick[i] = ptr->free_stick[next_stick];
}

void		send_all_brodcast(t_stick *ptr,
    void (*ptr_func)(t_stick *ptr,
      int i), int i)
{
  pthread_mutex_lock(&ptr->mutex);
  if (ptr_func != NULL)
    ptr_func(ptr, i);
  pthread_cond_broadcast(&ptr->cond);
  pthread_mutex_unlock(&ptr->mutex);
}

void		check_stick_free(t_stick *ptr,
    t_bool (*condition_fct)(t_stick *ptr,
      int i),
    int i, void (answer_fct)(t_stick *ptr, int i))
{
  if (pthread_mutex_lock(&ptr->mutex) == -1)
    mexit("Fail lock mutex.\n");
  if (ptr->free_stick[i] == TRUE)
    {
      g_philos[i] = THINK;
      printf("Le philosophe %d réfléchit.\n", i + 1);
    }
  else
    {
      printf("Le philosophe %d se repose.\n", i + 1);
      g_philos[i] = SLEEP;
    }
  while (! condition_fct(ptr, i))
    {
      if (pthread_cond_wait(&ptr->cond, &ptr->mutex) == -1)
	mexit("Fail to wait.\n");
    }
  if (answer_fct != NULL)
    answer_fct(ptr, i);
  if (pthread_mutex_unlock(&ptr->mutex) == -1)
    mexit("Fail to unlock");
}
