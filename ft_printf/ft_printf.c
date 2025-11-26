/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:45:20 by ruisilva          #+#    #+#             */
/*   Updated: 2025/11/26 18:28:33 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "ft_printf.h"

int	ft_printf(int fd, const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format != '%')
		{
			if (ftpf_putchar_fd(fd, *format, &count) == -1)
				return (va_end(args), -1);
		}
		else
		{
			format++;
			if (*format == '\0')
				return (va_end(args), -1);
			if (print_specifier_fd(fd, &args, *format, &count) == -1)
				return (va_end(args), -1);
		}
		format++;
	}
	va_end(args);
	return (count);
}
