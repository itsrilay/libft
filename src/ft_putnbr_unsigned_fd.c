/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:31:08 by ruisilva          #+#    #+#             */
/*   Updated: 2025/10/27 15:35:35 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned_fd(int fd, unsigned int num, int *count)
{
	char	c;

	if (num >= 10)
		if (ft_putnbr_unsigned_fd(fd, num / 10, count) == -1)
			return (-1);
	c = '0' + (num % 10);
	return (ft_putchar_fd(fd, c, count));
}
