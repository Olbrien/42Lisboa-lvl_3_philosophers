/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 02:41:56 by tisantos          #+#    #+#             */
/*   Updated: 2021/09/18 14:11:47 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <fcntl.h>

# define NOTHING 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3

# define MESSAGE_TAKEN_FORK 10
# define MESSAGE_EATING 11
# define MESSAGE_SLEEPING 12
# define MESSAGE_THINKING 13
# define MESSAGE_DIED 14
# define MESSAGE_TAKEN_SINGLE_FORK 15

typedef struct s_args
{
	int					nbr_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				eat_times;

	long				last_meal_global[500];

	struct timeval		start_time;
	struct timeval		passed_time;
	long				global_time;

	sem_t				*forks;

	int					has_anyone_died;
}			t_args;

typedef struct s_philo
{
	int					philo_nbr;

	int					is_alive;

	int					fork_on_left;
	int					fork_on_right;

	int					must_eat_times;

	long				last_meal;

	t_args				*args;
}			t_philo;

/*
** Initialize
*/

int				init_args(int argc, char **argv, t_args *args);
int				init_philosophers(t_args *args, t_philo **philo);

/*
** Process
*/

void			process(t_philo **philo_old);
void			update_the_time(t_philo *philo);
int				eating(t_philo *philo);
int				sleeping(t_philo *philo);
void			thinking(t_philo *philo);
void			mutex_lock_unlock(t_philo *philo, int i);
void			free_stuff(t_philo *philo, pid_t **pid);
int				usleep_duration(long n, t_philo *philo);
void			usleep_duration2(t_philo *philo, struct timeval *current);
int				usleep_duration3(t_philo *philo);

/*
** Actions
*/

void			action_take_forks(t_args *args);
void			action_eat(t_args *args);

/*
** Utils
*/

long long		ft_atoll(const char *str);
int				ft_isstringdigit(char *string);
void			display_message(t_philo *philo, int message);
void			update_the_time(t_philo *philo);

#endif
