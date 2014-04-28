/*
** philo.c for philo.c in /home/thibauj/rendu/philosophes
**
** Made by thibau_j
** Login   <thibau_j@epitech.net>
**
** Started on  Fri Mar 21 22:12:27 2014 thibau_j
** Last update dim. mars 23 19:22:58 2014 lefloc_l
*/

#include <stdio.h>
#include <unistd.h>
#include "philo.h"
#include "./Window.h"

int		g_philos[7];
t_stick		g_ptr;

static t_bool	init_struc(t_stick *ptr)
{
  int		i;

  i = 0;
  if (pthread_cond_init(&ptr->cond, NULL) == -1)
    {
      fprintf(stderr, "Initialisation of thread failed. addr:%p\n", ptr);
      return (FALSE);
    }
  if (pthread_mutex_init(&ptr->mutex, NULL) == -1)
    {
       fprintf(stderr, "Initialisation of thread failed. addr:%p\n", ptr);
       return (FALSE);
    }
  while (i < PHILO)
    {
      ptr->free_stick[i] = TRUE;
      i++;
    }
  ptr->status = UNKNOWN;
  return (TRUE);
}

void		run(int i)
{
  g_philos[i] = EAT;
  printf("Le philisophe %d mange.\n", i + 1);
  usleep(1000);
}

void		*philosophe_run(void *nb_philo)
{
  int		philo_nb;

  philo_nb = *(int *)nb_philo;
  while (42)
    {
      check_stick_free(&g_ptr, sticks_free, philo_nb, take_stick);
      run(philo_nb);
      send_all_brodcast(&g_ptr, freesticks, philo_nb);
    }
  return (0);
}

static t_bool	launcher()
{
  pthread_t	thread_tab[PHILO];
  int		nb_tab[PHILO];
  int		i;

  i = 0;

  while (i < PHILO)
    {
      nb_tab[i] = i;
      if (pthread_create(&thread_tab[i], NULL, philosophe_run,
            &nb_tab[i]) == -1)
        {
          fprintf(stderr, "Failed during the creation if the thread.\n");
          return (FALSE);
        }
      i++;
    }
  if (pthread_join(launch_sdl(), NULL) == -1)
    return (FALSE);
  printf("It's over.\n");
  return (TRUE);
}

int		main()
{
  if (init_struc(&g_ptr) == FALSE)
    return (-1);
  if (launcher() == FALSE)
    return (-1);
  return (0);
}
