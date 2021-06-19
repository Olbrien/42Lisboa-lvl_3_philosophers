/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:17:44 by tisantos          #+#    #+#             */
/*   Updated: 2021/06/19 20:16:44 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*multi_philo(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (philo->is_alive == 1 && philo->must_eat_times != 0
		&& philo->args->has_anyone_died == 0)
	{
		mutex_lock_unlock(philo, 0);
		if (eating(philo) == 0)
		{
			mutex_lock_unlock(philo, 1);
			break ;
		}
		mutex_lock_unlock(philo, 1);
		if (sleeping(philo) == 0)
			break ;
		thinking(philo);
	}
	if (philo->is_alive == 0)
		display_message(philo, MESSAGE_DIED);
	return (NULL);
}

void	*single_philo(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	display_message(philo, MESSAGE_TAKEN_SINGLE_FORK);
	usleep(philo->args->time_to_die);
	update_the_time(philo);
	philo->args->has_anyone_died = 1;
	display_message(philo, MESSAGE_DIED);
	return (NULL);
}

void	init_process(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->args->nbr_philo)
	{
		pthread_mutex_init(&philo->args->forks[i], NULL);
		i++;
	}
	gettimeofday(&philo->args->start_time, NULL);
}

void	process(t_philo **philo_old)
{
	t_philo	*philo;
	int		i;

	philo = *philo_old;
	i = 0;
	init_process(philo);
	while (i < philo->args->nbr_philo)
	{
		if (philo->args->nbr_philo == 1)
			pthread_create(&philo->args->t_id[i], NULL, single_philo,
				(void *)&philo[i]);
		else
			pthread_create(&philo->args->t_id[i], NULL, multi_philo,
				(void *)&philo[i]);
		i++;
	}
	i = 0;
	while (i < philo->args->nbr_philo)
	{
		pthread_join(philo->args->t_id[i], NULL);
		pthread_mutex_destroy(&philo->args->forks[i]);
		i++;
	}
	if (philo->args->has_anyone_died == 0)
		printf("%li everyone is satisfied\n", philo[0].args->global_time);
}
