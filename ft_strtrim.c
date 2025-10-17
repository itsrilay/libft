/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:25:12 by ruisilva          #+#    #+#             */
/*   Updated: 2025/10/14 13:58:58 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim(char const *set, char c);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;
	char	*init_str;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (trim(set, s1[i]))
		i++;
	while (trim(set, s1[j]))
		j--;
	if (i > j)
	{
		str = ft_calloc(1, sizeof(char));
		return (str);
	}
	str = ft_calloc((j - i) + 2, sizeof(char));
	if (!str)
		return (NULL);
	init_str = str;
	while (i < j + 1)
		*str++ = s1[i++];
	return (init_str);
}

static int	trim(char const *set, char c)
{
	while (*set)
	{
		if ((unsigned char)*set++ == (unsigned char)c)
			return (1);
	}
	return (0);
}
