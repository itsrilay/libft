/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:38:04 by ruisilva          #+#    #+#             */
/*   Updated: 2025/10/23 14:45:54 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	ch;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	while (*str)
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}
	if (ch == '\0')
		return ((char *)str);
	return (NULL);
}

char	*gnl_strdup(const char *s)
{
	char	*s2;
	char	*init_s2;

	s2 = malloc((gnl_strlen(s) + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	init_s2 = s2;
	while (*s)
		*s2++ = *s++;
	*s2 = '\0';
	return (init_s2);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*init_str;
	size_t	size;

	size = gnl_strlen(s1) + gnl_strlen(s2) + 1;
	str = malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	init_str = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (init_str);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > gnl_strlen(s))
		return (gnl_strdup(""));
	if (len > gnl_strlen(s + start))
		len = gnl_strlen(s + start);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
