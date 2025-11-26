/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:47:53 by ruisilva          #+#    #+#             */
/*   Updated: 2025/11/26 18:26:27 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_specifier_fd(int fd, va_list *args, char specifier, int *count)
{
	if (specifier == '%')
		return (ftpf_putchar_fd(fd, '%', count));
	else if (specifier == 'c')
		return (ftpf_putchar_fd(fd, va_arg(*args, int), count));
	else if (specifier == 's')
		return (ftpf_putstr_fd(fd, va_arg(*args, char *), count));
	else if (specifier == 'p')
		return (ftpf_putptr_fd(fd, va_arg(*args, void *), count));
	else if (specifier == 'd' || specifier == 'i')
		return (ftpf_putnbr_fd(fd, va_arg(*args, int), count));
	else if (specifier == 'u')
		return (ftpf_putnbr_unsigned_fd(fd, va_arg(*args, unsigned int),
				count));
	else if (specifier == 'x')
		return (ftpf_base16_fd(fd, va_arg(*args, unsigned int),
				"0123456789abcdef", count));
	else if (specifier == 'X')
		return (ftpf_base16_fd(fd, va_arg(*args, unsigned int),
				"0123456789ABCDEF", count));
	else
	{
		if (ftpf_putchar_fd(fd, '%', count) == -1)
			return (-1);
		return (ftpf_putchar_fd(fd, specifier, count));
	}
}
