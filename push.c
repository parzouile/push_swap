/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:48:34 by aschmitt          #+#    #+#             */
/*   Updated: 2023/12/01 17:13:32 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	update_index(a);
	update_index(b);
}

void	push_a(t_list **a, t_list **b)
{
	if (b != NULL)
	{
		push(a, b);
		printf("pa\n");
	}
}

void	push_b(t_list **a, t_list **b)
{
	if (a != NULL)
	{
		push(b, a);
		printf("pb\n");
	}
}
