/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:39:07 by tisantos          #+#    #+#             */
/*   Updated: 2021/06/14 11:18:00 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"


void	display_message(t_philo *philo, int message)
{
	if (message == MESSAGE_TAKEN_FORK)
	{
		printf("%li %i has taken a fork\n", philo->args->global_time, philo->philo_nbr);
		printf("%li %i has taken a fork\n", philo->args->global_time, philo->philo_nbr);
	}
	else if (message == MESSAGE_EATING)
		printf("%li %i is eating\n", philo->args->global_time, philo->philo_nbr);
	else if (message == MESSAGE_SLEEPING)
		printf("%li %i is sleeping\n", philo->args->global_time, philo->philo_nbr);
	else if (message == MESSAGE_THINKING)
		printf("%li %i is thinking\n", philo->args->global_time, philo->philo_nbr);

}
