/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:13:01 by aschmitt          #+#    #+#             */
/*   Updated: 2023/11/29 14:09:18 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    update_index(t_list **stack)
{
	int i;
	t_list  *tmp;

	tmp = *stack;
	i = -1;
	while (tmp != NULL)
	{
		tmp->index = ++i;
		tmp = tmp->next;
	}
}

void    rotate(t_list **stack)
{
	t_list  *tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
	update_index(stack);
}

void	rotate_a(t_list **a)
{
	rotate(a);
	write(0, "ra\n", 3);
}

void	rotate_b(t_list **b)
{
	rotate(b);
	write(0, "rb\n", 3);
}

void	rotate_ab(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write(0, "rr\n", 3);
}
