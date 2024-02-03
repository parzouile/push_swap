/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_push_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:43:05 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/26 15:42:56 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_all(t_list **a, t_list **b, t_list *node)
{
	while ((*a)->content != node->content
		&& (*b)->content != node->target->content)
		rotate_ab(a, b, 1);
}

void	reverse_rotate_all(t_list **a, t_list **b, t_list *node)
{
	while ((*a)->content != node->content
		&& (*b)->content != node->target->content)
		reverse_rotate_ab(a, b, 1);
}

static void	prepare_a(t_list **a, t_list *node, long size_a)
{
	if (node->index <= (size_a / 2))
	{
		while ((*a)->content != node->content)
			rotate_a(a, 1);
	}
	else
		while ((*a)->content != node->content)
			reverse_rotate_a(a, 1);
}

static void	prepare_b(t_list **a, t_list *node, long size_a)
{
	if (node->target->index <= (size_a / 2))
	{
		while ((*a)->content != node->target->content)
			rotate_b(a, 1);
	}
	else
		while ((*a)->content != node->target->content)
			reverse_rotate_b(a, 1);
}

void	prepare_push_a(t_list **a, t_list **b)
{
	long	size_a;
	long	size_b;
	t_list	*node;

	node = find_less_cost(*a);
	size_a = len_stack(*a);
	size_b = len_stack(*b);
	if (node->index <= (size_a / 2) && node->target->index <= (size_b / 2))
		rotate_all(a, b, node);
	else if (node->index > (size_a / 2) && node->target->index > (size_b / 2))
		reverse_rotate_all(a, b, node);
	prepare_a(a, node, size_a);
	prepare_b(b, node, size_b);
	push_b(a, b, 1);
}
