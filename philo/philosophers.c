/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 02:40:54 by tisantos          #+#    #+#             */
/*   Updated: 2021/06/13 19:46:37 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"

void	debug(t_args *args)
{
	int	i;

	i = 0;
	printf("\nPhilosophers = %lli\n", args->nbr_philo);
	printf("Time to die = %llims\n", args->time_to_die);
	printf("Time to eat = %llims\n", args->time_to_eat);
	printf("Time to sleep = %llims\n", args->time_to_sleep);
	printf("Must eat = %lli times each\n", args->eat_times);
	printf("\n------------------------------------------\n");

	while (i < args->nbr_philo)
	{
		printf("Philo number #%d\n", args->philo[i].philo_nbr);
		printf("Is alive %d\n", args->philo[i].is_alive);
		printf("Forks on hand %d\n", args->philo[i].forks_on_hand);
		printf("Fork on right %d\n", args->philo[i].fork_on_right);
		printf("Must eat times %d\n", args->philo[i].must_eat_times);
		printf("Last action %d\n", args->philo[i].last_action);
		printf("Start action time %lli\n", args->philo[i].start_action_time);
		printf("End action time %lli\n", args->philo[i].end_action_time);
		printf("\n------------------------------------------\n");
		i++;
	}
}

int	check_nbr_args(argc)
{
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("You need to insert 4 or 5 arguments.\n", 1);
		ft_putstr_fd("- Number of philosophers.\n", 1);
		ft_putstr_fd("- Time to die.   (ms)\n", 1);
		ft_putstr_fd("- Time to eat.   (ms)\n", 1);
		ft_putstr_fd("- Time to sleep. (ms)\n", 1);
		ft_putstr_fd("- Number of times each philosopher must eat. (opt)\n", 1);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_args args;

	if (check_nbr_args(argc) == 0)
		return (0);
	if (init_args(argc, argv, &args) == 0)
		return (0);
	if (init_philosophers(&args) == 0)
		return (0);

	process(&args);

	//debug(&args);





	free(args.philo);
	free(args.tid);

}
