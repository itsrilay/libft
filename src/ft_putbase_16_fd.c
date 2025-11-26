/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_16_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:31:19 by ruisilva          #+#    #+#             */
/*   Updated: 2025/10/27 15:35:16 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase_16_fd(int fd, unsigned long num, const char *base, int *count)
{
	char			c;
	unsigned long	base_len;

	base_len = 16;
	if (num >= base_len)
		if (ft_putbase_16_fd(fd, num / base_len, base, count) == -1)
			return (-1);
	c = base[num % base_len];
	return (ft_putchar_fd(fd, c, count));
}
