/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:33:23 by ruisilva          #+#    #+#             */
/*   Updated: 2025/10/27 16:44:51 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_fd(int fd, void *ptr, int *count)
{
	if (ptr == NULL)
		return (ft_putstr_fd(fd, "(nil)", count));
	if (ft_putstr_fd(fd, "0x", count) == -1)
		return (-1);
	if (ft_putbase_16_fd(fd, (unsigned long)ptr, "0123456789abcdef", count)
		== -1)
		return (-1);
	return (0);
}
