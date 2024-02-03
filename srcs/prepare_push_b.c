/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_push_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:56:29 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/24 13:15:30 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	prepare_a(t_list **a, t_list *node, long size_a)
{
	if (node->index <= (size_a / 2))
	{
		while ((*a)->content != node->content)
			rotate_b(a, 1);
	}
	else
		while ((*a)->content != node->content)
			reverse_rotate_b(a, 1);
}

static void	prepare_b(t_list **a, t_list *node, long size_a)
{
	if (node->target->index <= (size_a / 2))
	{
		while ((*a)->content != node->target->content)
			rotate_a(a, 1);
	}
	else
		while ((*a)->content != node->target->content)
			reverse_rotate_a(a, 1);
}

void	prepare_push_b(t_list **a, t_list **b)
{
	long	size_a;
	long	size_b;
	t_list	*node;

	node = find_less_cost(*b);
	size_a = len_stack(*a);
	size_b = len_stack(*b);
	if (node->index <= (size_b / 2) && node->target->index <= (size_a / 2))
		rotate_all(b, a, node);
	else if (node->index > (size_b / 2) && node->target->index > (size_a / 2))
		reverse_rotate_all(b, a, node);
	prepare_a(b, node, size_b);
	prepare_b(a, node, size_a);
	push_a(a, b, 1);
}
