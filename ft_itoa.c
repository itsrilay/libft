/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:33:35 by ruisilva          #+#    #+#             */
/*   Updated: 2025/10/15 18:15:21 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_int(int n);
static void	make_str(char *str, int n, int count);

char	*ft_itoa(int n)
{
	int		count;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	count = count_int(n);
	str = malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	make_str(str, n, count);
	return (str);
}

static void	make_str(char *str, int n, int count)
{
	str[count] = '\0';
	if (n < 0)
	{
		*str = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[--count] = '0' + (n % 10);
		n /= 10;
	}
}

static int	count_int(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	printf("Output: %s\n", ft_itoa(2147483647));
// 	printf("Output: %s\n", ft_itoa(-2147483648));
// 	printf("Output: %s\n", ft_itoa(0));
// }