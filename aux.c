/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:39:27 by aschmitt          #+#    #+#             */
/*   Updated: 2023/12/01 16:53:50 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
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

long	ft_atoi(const char *str)
{
	long		n;
	long		sign;
	size_t	i;

	n = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i ++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
        if ((n * sign) > 2147483647 || (n * sign) < -2147483648)
            return (2147483648);
		i ++;
	}
	return (n * sign);
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

void    print_stack(t_list *a)
{
	while (a != NULL)
	{
		if (a->target != NULL)
			printf("node = %ld et index = %ld et target = %ld\n", a->content, a->index, a->target->content);
		else
			printf("node = %ld et index = %ld\n", a->content, a->index);
		a = a->next;
	}
}
