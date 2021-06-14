/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 02:41:56 by tisantos          #+#    #+#             */
/*   Updated: 2021/06/14 01:24:57 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>

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
	long long int		nbr_philo;
	long long int		time_to_die;
	long long int		time_to_eat;
	long long int		time_to_sleep;
	long long int		eat_times;

	pthread_t 			*t_id;
	pthread_mutex_t 	*forks;
}			t_args;

typedef struct s_philo
{
	int					philo_nbr;

	int					is_alive;

	int					fork_on_left;
	int					fork_on_right;

	int					must_eat_times;

	int					last_action;

	long long int		start_action_time;
	long long int		end_action_time;

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

void			ft_putstr_fd(char *s, int fd);
long long		ft_atoll(const char *str);
int				ft_isstringdigit(char *string);

void			display_message(t_args *args, int message);



#endif
