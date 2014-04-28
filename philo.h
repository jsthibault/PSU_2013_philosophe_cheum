/*
** philo.h for philosophes in /home/loic/dev/epitech/c/philosophes
**
** Made by lefloc_l
** Login <lefloc_l@epitech.eu>
**
** Started on  lun. mars 17 22:22:04 2014 lefloc_l
** Last update dim. mars 23 02:32:57 2014 lefloc_l
*/

#ifndef PHILO_H_
# define PHILO_H_

# define PHILO 7
# define TPS_S 3

# include <stdio.h>
# include <pthread.h>

typedef enum	e_bool
{
  FALSE,
  TRUE
}		t_bool;

typedef enum	e_state
{
  SLEEP,
  THINK,
  EAT,
  UNKNOWN
}		t_state;

typedef struct		s_stick
{
  pthread_cond_t	cond;
  pthread_mutex_t	mutex;
  t_state		status;
  t_bool		free_stick[PHILO];
}			t_stick;

void			*thread(void *arg);
t_bool			sticks_free(t_stick *ptr, int i);
void			take_stick(t_stick *ptr, int i);
void			freesticks(t_stick *ptr, int i);

void		check_stick_free(t_stick *ptr,
    t_bool (*condition_fct)(t_stick *ptr, int i),
    int i, void (answer_fct)(t_stick *ptr, int i));
void		send_all_brodcast(t_stick *ptr,
    void (*ptr_func)(t_stick *ptr, int i), int i);

#endif /* !PHILO_H_ */
