/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:30:48 by ruisilva          #+#    #+#             */
/*   Updated: 2025/11/26 18:24:39 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftpf_putchar_fd(int fd, const char c, int *count)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	*count += 1;
	return (0);
}
