/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:09:17 by ruisilva          #+#    #+#             */
/*   Updated: 2025/10/15 11:53:21 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(int c);

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (isspace((int)*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + ((int)*str - '0');
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

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	printf("Output: %d, Expected: %d\n",
// ft_atoi("2147483647"), atoi("2147483647"));
// 	printf("Output: %d, Expected: %d\n",
// ft_atoi("-2147483648"), atoi("-2147483648"));
// 	printf("Output: %d, Expected: %d\n",
// ft_atoi("-+2147483647"), atoi("-+2147483647"));
// }