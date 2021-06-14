/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:17:44 by tisantos          #+#    #+#             */
/*   Updated: 2021/06/14 02:06:00 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*process_actions(void *args)
{

}

void	process(t_philo **philo_old)
{
	t_philo	*philo;
	int		i;

	philo = *philo_old;

	while(i < philo->args->nbr_philo)
	{
		pthread_create(&philo->args->t_id[i], NULL, process_actions, NULL);
		i++;
	}

	i = 0;

	while(i < philo->args->nbr_philo)
	{
		pthread_join(philo->args->t_id[i], NULL);
		i++;
	}

}


//if (philosopher dead)
//if (must eat everyrone == 0 )
//else
//process(args);


 // Conditions to leave this recursive function.
 //	If must eat is > 0, everyone needs to have 0.
 //	If a philosopher died.
