/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:46:33 by ruisilva          #+#    #+#             */
/*   Updated: 2025/10/15 16:21:04 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	temp = ft_lstlast(*lst);
	if (!temp)
		*lst = new;
	else
		temp->next = new;
}

// #include <stdio.h>
// void print_list(void *content)
// {
// 	printf("%s\n", (char *)content);
// }

// int	main(void)
// {
// 	t_list *list = NULL;
//     list = ft_lstnew(ft_strdup("Node 1"));
//     list->next = ft_lstnew(ft_strdup("Node 2"));
//     list->next->next = ft_lstnew(ft_strdup("Node 3"));

// 	ft_lstiter(list, print_list);
// }