/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:19:35 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/24 13:27:50 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	update_index(a);
	update_index(b);
}

void	push_a(t_list **a, t_list **b, int print)
{
	if (*b == NULL)
		return ;
	push(a, b);
	if (print)
		ft_putstr("pa\n");
}

void	push_b(t_list **a, t_list **b, int print)
{
	if (*a == NULL)
		return ;
	push(b, a);
	if (print)
		ft_putstr("pb\n");
}
