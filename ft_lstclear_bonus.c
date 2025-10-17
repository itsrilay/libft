/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:56:38 by ruisilva          #+#    #+#             */
/*   Updated: 2025/10/17 10:36:55 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}

// #include <stdio.h>
// void print_list(void *content)
// {
// 	printf("%s\n", (char *)content);
// }

// void del(void *content)
// {
// 	free(content);
// }

// char	*ft_strdup(const char *s)
// {
// 	char	*s2;
// 	char	*init_s2;

// 	s2 = malloc((ft_strlen(s) + 1) * sizeof(char));
// 	if (!s2)
// 		return (NULL);
// 	init_s2 = s2;
// 	while (*s)
// 		*s2++ = *s++;
// 	*s2 = '\0';
// 	return (init_s2);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// int	main(void)
// {
// 	t_list *list = NULL;
//     list = ft_lstnew(ft_strdup("Node 1"));
//     list->next = ft_lstnew(ft_strdup("Node 2"));
//     list->next->next = ft_lstnew(ft_strdup("Node 3"));

// 	ft_lstiter(list, print_list);
// 	ft_lstclear(&list, del);
// 	if (list == NULL)
// 		printf("List cleared");
// 	else
// 		printf("List NOT cleared");
// }