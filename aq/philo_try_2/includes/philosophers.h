/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 02:41:56 by tisantos          #+#    #+#             */
/*   Updated: 2021/06/14 13:00:54 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

#define NOTHING 0
#define EATING 1
#define SLEEPING 2
#define THINKING 3

#define MESSAGE_TAKEN_FORK 10
#define MESSAGE_EATING 11
#define MESSAGE_SLEEPING 12
#define MESSAGE_THINKING 13
#define MESSAGE_DIED 14


typedef struct s_args
{
	int				nbr_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			eat_times;

	struct timeval		start_time;
	struct timeval		passed_time;
	long				global_time;

	pthread_t 			*t_id;
	pthread_mutex_t 	*forks;
	pthread_mutex_t		mutex_time;

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



#endif
