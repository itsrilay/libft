/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:29:58 by ruisilva          #+#    #+#             */
/*   Updated: 2025/10/15 15:59:57 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*temp;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb >= SIZE_MAX / size)
		return (NULL);
	temp = malloc(nmemb * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, nmemb * size);
	return (temp);
}

// int	main(void)
// {
// 	char *str;
// 	char *str2;

// 	str = ft_calloc(1, 1);
// 	free(str);
// 	str2 = ft_calloc(SIZE_MAX, 0);
// 	free(str2);
// }