/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 11:32:24 by tisantos          #+#    #+#             */
/*   Updated: 2021/06/14 01:12:56 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	init_philosophers2(t_args *args, t_philo **philo)
{
	t_philo *temp;
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * args->nbr_philo);
	temp = *philo;
	while (i < args->nbr_philo)
	{
		temp[i].philo_nbr = i + 1;
		temp[i].is_alive = 1;
		temp[i].fork_on_left = 0;
		temp[i].fork_on_right = 1;
		temp[i].must_eat_times = args->eat_times;
		temp[i].last_action = NOTHING;
		temp[i].start_action_time = 0;
		temp[i].end_action_time = 0;
		temp[i].args = args;
		*philo = temp;
		i++;
	}
}

int	init_philosophers(t_args *args, t_philo **philo)
{
	if (args->eat_times == 0)
	{
		ft_putstr_fd("0 all philosophers have eaten the required amount.\n", 1);
		free(args->forks);
		free(args->t_id);
		return (0);
	}
	init_philosophers2(args, philo);
	return (1);
}

int	validate_args(int argc, char **argv, t_args *args)
{
	if (ft_isstringdigit(argv[1]) == 0 || ft_isstringdigit(argv[2]) == 0
		|| ft_isstringdigit(argv[3]) == 0 || ft_isstringdigit(argv[4]) == 0
		|| argc == 6 && ft_isstringdigit(argv[5]) == 0)
	{
		ft_putstr_fd("You need to insert numerical values in all fields.\n", 1);
		return (0);
	}
	if (args->nbr_philo <= 0 || args->time_to_die <= 0
		|| args->time_to_eat <= 0 || args->time_to_sleep <= 0
		|| args->eat_times < 0 && argc == 6)
	{
		ft_putstr_fd("You need to insert values superior to 0 in all fields ", 1);
		ft_putstr_fd("except argument 5.\n", 1);
		return (0);
	}
	return (1);
}

int	init_args(int argc, char **argv, t_args *args)
{
	args->nbr_philo = ft_atoll(argv[1]);
	args->time_to_die = ft_atoll(argv[2]);
	args->time_to_eat = ft_atoll(argv[3]);
	args->time_to_sleep = ft_atoll(argv[4]);
	if (argc == 6)
		args->eat_times = ft_atoll(argv[5]);
	else
		args->eat_times = -1;

	args->forks = malloc(sizeof(pthread_mutex_t) * args->nbr_philo);
	args->t_id = malloc(sizeof(pthread_mutex_t) * args->nbr_philo);

	if (validate_args(argc, argv, args) == 0)
	{
		free(args->forks);
		free(args->t_id);
		return (0);
	}

	return (1);
}


