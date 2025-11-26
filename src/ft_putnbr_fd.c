/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:48:02 by ruisilva          #+#    #+#             */
/*   Updated: 2025/10/14 13:58:11 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	temp;
	char		c;

	temp = n;
	if (temp < 0)
	{
		write(fd, "-", 1);
		temp = -temp;
	}
	if (temp > 9)
	{
		ft_putnbr_fd(temp / 10, fd);
	}
	c = '0' + (temp % 10);
	write(fd, &c, 1);
}
