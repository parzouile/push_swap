/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:21:58 by aschmitt          #+#    #+#             */
/*   Updated: 2023/11/28 19:09:59 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_all(t_list **a, t_list **b, t_list *node)
{
	while ((*a)->content != node->content && (*b)->content != node->target->content)
		rotate_ab(a, b);
	while ((*a)->content != node->content)
		rotate_a(a);
	while ((*b)->content != node->target->content)
		rotate_b(b);
}

void	reverse_rotate_all(t_list **a, t_list **b, t_list *node)
{
	while ((*a)->content != node->content && (*b)->content != node->target->content)
		reverse_rotate_ab(a, b);
	while ((*a)->content != node->content)
		reverse_rotate_a(a);
	while ((*b)->content != node->target->content)
		reverse_rotate_b(b);
}

void	prepare_push(t_list **a, t_list **b, t_list *node)
{
	long	size_a;
	long	size_b;

	size_a = len_stack(*a);
	size_b = len_stack(*b);
	if (node->index <= (size_a / 2) && node->target->index <= (size_b / 2))
		rotate_all(a, b, node);
	else if (node->index > (size_a / 2) && node->target->index > (size_b / 2))
		reverse_rotate_all(a, b, node);
	prepare_a(a, node);
	prepare_b(b, node);
	push_b(a, b);
}

t_list	*find_less_cost(t_list *a)
{
	t_list	*less_cost;

	less_cost = a;
	a = a->next;
	while (a)
	{
		if (a->cost < less_cost->cost)
			less_cost = a;
		a = a->next;
	}
	return (less_cost);
}