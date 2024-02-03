/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:18:54 by aschmitt          #+#    #+#             */
/*   Updated: 2023/12/18 14:48:50 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(long content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}

void	ft_lstclear(t_list **lst)
{
	if (*lst == NULL)
		return ;
	if ((*lst)->next != NULL)
		ft_lstclear((&(*lst)->next));
	free(*lst);
	*lst = NULL;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
