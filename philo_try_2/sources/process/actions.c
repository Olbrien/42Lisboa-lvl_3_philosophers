/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 15:37:23 by tisantos          #+#    #+#             */
/*   Updated: 2021/06/13 20:32:05 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"
/*
void	action_take_forks(t_args *args)
{
	int		tid_i;
	int		forks;

	tid_i = args->tid_i;
	forks = 0;

	if (args->philo[tid_i].forks_on_hand == 2)
		return ;

	if (args->philo[tid_i].fork_on_right == 1)
		forks++;
	if (tid_i + 1 >= args->nbr_philo && args->philo[0].fork_on_right == 1)
		forks++;
	else if (args->philo[tid_i + 1].fork_on_right == 1)
		forks++;

	if (forks == 2)
	{
		if (args->philo[tid_i].fork_on_right == 1)
			args->philo[tid_i].fork_on_right = 0;
		if (tid_i + 1 > args->nbr_philo && args->philo[0].fork_on_right == 1)
			args->philo[0].fork_on_right = 0;
		else if (args->philo[tid_i + 1].fork_on_right == 1)
			args->philo[tid_i + 1].fork_on_right = 0;
		args->philo[tid_i].forks_on_hand = 2;
		display_message(args, MESSAGE_TAKEN_FORK);
	}
}

void	action_eat(t_args *args)
{
	int		tid_i;

	tid_i = args->tid_i;

	//printf("---->%i = %i\n", args->philo[tid_i].forks_on_hand, args->tid_i);

	if (args->philo[tid_i].forks_on_hand != 2)
		return ;

	printf("EU TENHHO!!! %i\n", tid_i);
}
*/
