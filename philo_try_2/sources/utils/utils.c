/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 02:50:49 by tisantos          #+#    #+#             */
/*   Updated: 2021/06/14 12:03:05 by tisantos         ###   ########.fr       */
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
	else if (message == MESSAGE_DIED)
		printf("%li %i died\n", philo->args->global_time, philo->philo_nbr);

}

long long	ft_atoll(const char *str)
{
	long long	ret;
	long long	checker;
	int			sign;

	ret = 0;
	checker = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || \
			*str == '\f' || *str == '\r' || *str == ' ')
		++str;
	if (*str && (*str == 43 || *str == 45))
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		ret = ret * 10 + (*str - 48);
		if (checker > ret && sign == 1)
			return (9223372036854775807);
		else if (checker > ret && sign == -1)
			return (-9223372036854775807);
		str++;
	}
	return (ret * sign);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	ft_isstringdigit(char *string)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (string[i] != '\0')
	{
		if (i == 0 && string[i] == '-')
		{
			i++;
			continue ;
		}
		if (ft_isdigit(string[i]) == 1)
			a = 1;
		else
			return (0);
		i++;
	}
	return (a);
}
