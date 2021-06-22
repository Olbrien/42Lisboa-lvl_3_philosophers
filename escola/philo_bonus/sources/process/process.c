/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:17:44 by tisantos          #+#    #+#             */
/*   Updated: 2021/06/20 00:20:37 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	multi_philo(t_philo *philo)
{
	while (philo->is_alive == 1 && philo->must_eat_times != 0
		&& philo->args->has_anyone_died == 0)
	{
		sem_wait(philo->args->forks);
		if (eating(philo) == 0)
		{
			sem_post(philo->args->forks);
			break ;
		}
		sem_post(philo->args->forks);
		if (sleeping(philo) == 0)
			break ;
		thinking(philo);
	}
	if (philo->is_alive == 0)
		display_message(philo, MESSAGE_DIED);
}

void	single_philo(t_philo *philo)
{
	display_message(philo, MESSAGE_TAKEN_SINGLE_FORK);
	usleep(philo->args->time_to_die);
	update_the_time(philo);
	philo->args->has_anyone_died = 1;
	display_message(philo, MESSAGE_DIED);
}

void	init_process(t_philo *philo, pid_t **pid)
{
	int	i;

	i = 0;
	sem_unlink("forks");
	philo->args->forks = sem_open("forks", O_CREAT, S_IRWXU,
			(philo->args->nbr_philo / 2));
	gettimeofday(&philo->args->start_time, NULL);
	*pid = malloc(sizeof(pid_t) * philo->args->nbr_philo);
}

void	process2(t_philo *philo, int i, pid_t *pid)
{
	if (philo[i].must_eat_times == 0 && philo->args->nbr_philo != 1)
	{
		if (pid == 0 && philo[i].args->has_anyone_died == 1)
			exit (1);
		printf("%li everyone is satisfied\n", philo[0].args->global_time);
		while (i < philo->args->nbr_philo)
			exit(1);
	}
	waitpid(-1, NULL, 0);
	i = 0;
	while (i < philo->args->nbr_philo)
		kill(pid[i++], SIGTERM);
	sem_close(philo->args->forks);
	sem_unlink("forks");
	free(pid);
	free(philo);
}

void	process(t_philo **philo_old)
{
	t_philo	*philo;
	int		i;
	pid_t	*pid;

	philo = *philo_old;
	i = 0;
	init_process(philo, &pid);
	while (i < philo->args->nbr_philo)
	{
		pid[i] = fork();
		if (pid[i] == 0 && philo->args->nbr_philo == 1)
		{
			single_philo(&philo[i]);
			exit(1);
		}
		else if (pid[i] == 0 && philo->args->nbr_philo > 1)
		{
			multi_philo(&philo[i]);
			if (philo[i].must_eat_times != 0)
				exit(1);
			break ;
		}
		i++;
	}
	process2(philo, i, pid);
}
