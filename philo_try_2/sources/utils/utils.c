/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 02:50:49 by tisantos          #+#    #+#             */
/*   Updated: 2021/06/13 09:42:16 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
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
