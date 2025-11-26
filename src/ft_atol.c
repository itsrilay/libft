/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:28:42 by ruisilva          #+#    #+#             */
/*   Updated: 2025/11/26 16:01:54 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(int c);

long	ft_atol(const char *str)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	while (isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (sign * num);
}

static int	isspace(int c)
{
	if (c == '\t' || c == '\v' || c == '\n' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}
