/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:17:44 by tisantos          #+#    #+#             */
/*   Updated: 2021/06/14 11:34:13 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	update_the_time(t_philo *philo)
{
	long long int diff;

	gettimeofday(&philo->args->passed_time, NULL);

	diff = (philo->args->passed_time.tv_sec - philo->args->start_time.tv_sec)
		* 1000 + (philo->args->passed_time.tv_usec -
		philo->args->start_time.tv_usec) / 1000;

	philo->args->global_time = diff;
}

void	*process_actions(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;

	while(philo->is_alive == 1 || philo->must_eat_times == 0)
	{
		pthread_mutex_lock(&philo->args->forks[philo->fork_on_left]);
		pthread_mutex_lock(&philo->args->forks[philo->fork_on_right]);

		display_message(philo, MESSAGE_TAKEN_FORK);
		display_message(philo, MESSAGE_EATING);
		usleep(philo->args->time_to_eat);

		pthread_mutex_unlock(&philo->args->forks[philo->fork_on_left]);
		pthread_mutex_unlock(&philo->args->forks[philo->fork_on_right]);

		update_the_time(philo);
		display_message(philo, MESSAGE_SLEEPING);

		usleep(philo->args->time_to_sleep);

		update_the_time(philo);
		display_message(philo, MESSAGE_THINKING);

		break;

	}
	if (philo->is_alive == 0)
		ft_putstr_fd("Philosopher died!!!\n", 1);

	return (NULL);
}

void	init_pthread_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->args->nbr_philo)
	{
		pthread_mutex_init(&philo->args->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&philo->args->mutex_time, NULL);
}

void	process(t_philo **philo_old)
{
	t_philo	*philo;
	int		i;

	philo = *philo_old;
	i = 0;

	init_pthread_mutex(philo);
	gettimeofday(&philo->args->start_time, NULL);

	while(i < philo->args->nbr_philo)
	{
		pthread_create(&philo->args->t_id[i], NULL, process_actions, (void *)&philo[i]);
		i++;
	}

	i = 0;

	while(i < philo->args->nbr_philo)
	{
		pthread_join(philo->args->t_id[i], NULL);
		pthread_mutex_destroy(&philo->args->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->args->mutex_time);

}
