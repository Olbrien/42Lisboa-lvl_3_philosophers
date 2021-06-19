/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:15:00 by tisantos          #+#    #+#             */
/*   Updated: 2021/06/19 20:17:25 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	mutex_lock_unlock(t_philo *philo, int i)
{
	if (i == 0)
	{
		pthread_mutex_lock(&philo->args->forks[philo->fork_on_left]);
		pthread_mutex_lock(&philo->args->forks[philo->fork_on_right]);
	}
	else
	{
		pthread_mutex_unlock(&philo->args->forks[philo->fork_on_left]);
		pthread_mutex_unlock(&philo->args->forks[philo->fork_on_right]);
	}
}

int	usleep_duration(long n, t_philo *philo)
{
	struct timeval	start;
	struct timeval	current;

	gettimeofday(&start, NULL);
	while (philo->args->has_anyone_died == 0)
	{
		usleep(50);
		update_the_time(philo);
		gettimeofday(&current, NULL);
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
	}
	if (philo->args->has_anyone_died == 1)
		return (0);
	return (1);
}

void	thinking(t_philo *philo)
{
	update_the_time(philo);
	display_message(philo, MESSAGE_THINKING);
}

int	sleeping(t_philo *philo)
{
	if (philo->args->has_anyone_died == 1)
		return (0);
	update_the_time(philo);
	display_message(philo, MESSAGE_SLEEPING);
	if (usleep_duration(philo->args->time_to_sleep, philo) == 0)
		return (0);
	else
		return (1);
}

int	eating(t_philo *philo)
{
	if (philo->args->has_anyone_died == 1)
		return (0);
	if (philo->args->global_time - philo->last_meal
		> philo->args->time_to_die / 1000)
	{
		philo->is_alive = 0;
		philo->args->has_anyone_died = 1;
		return (0);
	}
	philo->last_meal = philo->args->global_time;
	display_message(philo, MESSAGE_EATING);
	if (usleep_duration(philo->args->time_to_eat, philo) == 0)
		return (0);
	philo->must_eat_times--;
	return (1);
}
