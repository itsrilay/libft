/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:30:53 by ruisilva          #+#    #+#             */
/*   Updated: 2025/11/26 18:25:06 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftpf_putstr_fd(int fd, const char *str, int *count)
{
	if (!str)
		return (ftpf_putstr_fd(fd, "(null)", count));
	while (*str)
		if (ftpf_putchar_fd(fd, *str++, count) == -1)
			return (-1);
	return (0);
}
