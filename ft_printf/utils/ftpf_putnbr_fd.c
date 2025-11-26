/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:30:50 by ruisilva          #+#    #+#             */
/*   Updated: 2025/11/26 18:24:36 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftpf_putnbr_fd(int fd, int num, int *count)
{
	char	c;

	if (num == -2147483648)
		return (ftpf_putstr_fd(fd, "-2147483648", count));
	if (num < 0)
	{
		num = -num;
		if (ftpf_putchar_fd(fd, '-', count) == -1)
			return (-1);
	}
	if (num >= 10)
		if (ftpf_putnbr_fd(fd, num / 10, count) == -1)
			return (-1);
	c = '0' + (num % 10);
	return (ftpf_putchar_fd(fd, c, count));
}
