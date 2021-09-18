/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:15:00 by tisantos          #+#    #+#             */
/*   Updated: 2021/09/18 14:12:59 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

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
	update_the_time(philo);
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
	philo->args->last_meal_global[philo->philo_nbr] = philo->last_meal;
	display_message(philo, MESSAGE_EATING);
	if (usleep_duration(philo->args->time_to_eat, philo) == 0)
		return (0);
	philo->must_eat_times--;
	return (1);
}
