/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:15:00 by tisantos          #+#    #+#             */
/*   Updated: 2021/09/18 14:11:18 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	usleep_duration3(t_philo *philo)
{
	int	i;

	i = 1;
	while (i < philo->args->nbr_philo
		&& philo->args->has_anyone_died == 0)
	{
		if (philo->args->global_time - philo->args->last_meal_global[i]
			> philo->args->time_to_die / 1000)
		{
			philo->args->has_anyone_died = 1;
			printf("%li %i died\n", philo->args->global_time, i);
			return (0);
		}
		i++;
	}
	return (1);
}

void	usleep_duration2(t_philo *philo, struct timeval *current)
{
	usleep(50);
	update_the_time(philo);
	gettimeofday(current, NULL);
}

int	usleep_duration(long n, t_philo *philo)
{
	struct timeval	start;
	struct timeval	current;

	gettimeofday(&start, NULL);
	while (philo->args->has_anyone_died == 0)
	{
		usleep_duration2(philo, &current);
		if (((current.tv_sec - start.tv_sec) * 1000000
				+ (current.tv_usec - start.tv_usec)) > n)
			break ;
		if (philo->must_eat_times == 0)
			return (0);
		if (philo->args->global_time - philo->last_meal
			> philo->args->time_to_die / 1000)
		{
			philo->is_alive = 0;
			philo->args->has_anyone_died = 1;
			return (0);
		}		
		if (usleep_duration3(philo) == 0)
			return (0);
	}
	if (philo->args->has_anyone_died == 1)
		return (0);
	return (1);
}
