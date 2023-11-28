/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_push_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:51:15 by aschmitt          #+#    #+#             */
/*   Updated: 2023/11/28 22:52:12 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	prepare_push_a(t_list **a, t_list **b, t_list *node)
{
	long	size_a;
	long	size_b;

	size_a = len_stack(*a);
	size_b = len_stack(*b);
	if (node->index <= (size_a / 2) && node->target->index <= (size_b / 2))
		rotate_all(a, b, node);
	else if (node->index > (size_a / 2) && node->target->index > (size_b / 2))
		reverse_rotate_all(a, b, node);
	prepare_a(a, node, size_a);
	prepare_b(b, node, size_b);
	push_a(a, b);
}
