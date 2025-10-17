/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:20:09 by ruisilva          #+#    #+#             */
/*   Updated: 2025/10/17 10:53:10 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c);
static void	free_arr(char **arr);
static char	*get_word(char const *s, char c);
static int	build_arr(char const *s, char **arr, int size, char c);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		size;
	int		is_built;

	if (!s)
		return (NULL);
	size = word_count(s, c) + 1;
	arr = ft_calloc(size, sizeof(char *));
	if (!arr)
		return (NULL);
	is_built = build_arr(s, arr, size, c);
	if (!is_built)
		return (NULL);
	return (arr);
}

static int	build_arr(char const *s, char **arr, int size, char c)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		while (*s == c && *s)
			s++;
		if (!*s)
			break ;
		arr[i] = get_word(s, c);
		if (!arr[i])
		{
			free_arr(arr);
			return (0);
		}
		while (*s != c && *s)
			s++;
		i++;
	}
	arr[i] = NULL;
	return (1);
}

static void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static char	*get_word(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	word = ft_calloc(i + 1, sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, i + 1);
	return (word);
}

static int	word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

// #include <stdio.h>
// void print_split_result(char **result)
// {
// 	int i = 0;
// 	if (!result)
// 	{
// 		printf("NULL returned.\n");
// 		return ;
// 	}
// 	while (result[i])
// 	{
// 		printf("result[%d]: \"%s\"\n", i, result[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

// void free_split_result(char **result)
// {
// 	int i = 0;
// 	while (result && result[i])
// 		free(result[i++]);
// 	free(result);
// }

// int main(void)
// {
// 	char **result;

// 	printf("Test 1: \"Hello world  this is C\"\n");
// 	result = ft_split("Hello world  this is C", ' ');
// 	print_split_result(result);
// 	free_split_result(result);

// 	return (0);
// }