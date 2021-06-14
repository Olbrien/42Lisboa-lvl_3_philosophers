/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:17:44 by tisantos          #+#    #+#             */
/*   Updated: 2021/06/13 23:31:58 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*process_actions(void *args)
{
	t_args	*data;

	data = (t_args *)args;

	if (data->nbr_philo > 1 && data->philo[data->tid_i].last_action == NOTHING
		|| data->philo[data->tid_i].last_action == THINKING)
	{
		pthread_mutex_lock(&data->mutex);
		action_take_forks(data);
		action_eat(data);
		pthread_mutex_unlock(&data->mutex);
	}

	return (NULL);

}

void	process(t_args *args)
{
	int	i;

	i = 0;
	pthread_mutex_init(&args->mutex, NULL);
	while (i < args->nbr_philo)
	{
		pthread_create(&args->tid[i], NULL, process_actions, (void *)args);
		args->tid_i++;
		usleep(250);
		i++;
	}
	i = 0;
	while (i < args->nbr_philo)
		pthread_join(args->tid[i++], NULL);

	//if (philosopher dead)
	//if (must eat everyrone == 0 )
	//else
	//process(args);
	pthread_mutex_destroy(&args->mutex);


 // Conditions to leave this recursive function.
 //	If must eat is > 0, everyone needs to have 0.
 //	If a philosopher died.


}
