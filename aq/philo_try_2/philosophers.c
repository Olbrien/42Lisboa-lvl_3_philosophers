/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 02:40:54 by tisantos          #+#    #+#             */
/*   Updated: 2021/06/14 12:03:48 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"

void	debug(t_philo *philo)
{
	int	i;

	i = 0;
	printf("\nPhilosophers = %i\n", philo[i].args->nbr_philo);
	printf("Time to die = %lims\n", philo[i].args->time_to_die);
	printf("Time to eat = %lims\n", philo[i].args->time_to_eat);
	printf("Time to sleep = %lims\n", philo[i].args->time_to_sleep);
	printf("Must eat = %li times each\n", philo[i].args->eat_times);
	printf("\n------------------------------------------\n");

	while (i < philo->args->nbr_philo)
	{
		printf("Philo number #%d\n", philo[i].philo_nbr);
		printf("Is alive %d\n", philo[i].is_alive);
		printf("Fork on left hand %d\n", philo[i].fork_on_left);
		printf("Fork on right hand %d\n", philo[i].fork_on_right);
		printf("Must eat times %d\n", philo[i].must_eat_times);
		printf("Last meal %li\n", philo[i].last_meal);
		printf("\n------------------------------------------\n");
		i++;
	}
}

int	check_nbr_args(argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("You need to insert 4 or 5 arguments.\n");
		printf("- Number of philosophers.\n");
		printf("- Time to die.   (ms)\n");
		printf("- Time to eat.   (ms)\n");
		printf("- Time to sleep. (ms)\n");
		printf("- Number of times each philosopher must eat. (opt)\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_args args;
	t_philo *philo;

	if (check_nbr_args(argc) == 0)
		return (0);
	if (init_args(argc, argv, &args) == 0)
		return (0);
	if (init_philosophers(&args, &philo) == 0)
		return (0);

	//debug(philo);

	process(&philo);




	free(args.forks);
	free(args.t_id);
	free(philo);



}
