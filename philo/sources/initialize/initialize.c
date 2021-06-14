/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 11:32:24 by tisantos          #+#    #+#             */
/*   Updated: 2021/06/13 18:29:54 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"


int	init_philosophers(t_args *args)
{
	int	i;

	i = 0;
	if (args->eat_times == 0)
	{
		ft_putstr_fd("0 all philosophers have eaten the required amount.\n", 1);
		free(args->tid);
		return (0);
	}
	args->philo = malloc(sizeof(t_philo) * args->nbr_philo);
	while (i < args->nbr_philo)
	{
		args->philo[i].philo_nbr = i + 1;
		args->philo[i].is_alive = 1;
		args->philo[i].forks_on_hand = 0;
		args->philo[i].fork_on_right = 1;
		args->philo[i].must_eat_times = args->eat_times;
		args->philo[i].last_action = NOTHING;
		args->philo[i].start_action_time = 0;
		args->philo[i].end_action_time = 0;
		i++;
	}
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

	if (validate_args(argc, argv, args) == 0)
		return (0);

	args->tid = malloc(sizeof(pthread_t) * args->nbr_philo);
	args->tid_i = 0;

	return (1);
}


