/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:16:50 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/24 13:28:55 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
	update_index(stack);
}

void	rotate_a(t_list **a, int print)
{
	if (*a == NULL)
		return ;
	rotate(a);
	if (print)
		ft_putstr("ra\n");
}

void	rotate_b(t_list **b, int print)
{
	if (*b == NULL)
		return ;
	rotate(b);
	if (print)
		ft_putstr("rb\n");
}

void	rotate_ab(t_list **a, t_list **b, int print)
{
	if (*a == NULL || *b == NULL)
		return ;
	rotate(a);
	rotate(b);
	if (print)
		ft_putstr("rr\n");
}
