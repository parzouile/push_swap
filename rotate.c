/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:13:01 by aschmitt          #+#    #+#             */
/*   Updated: 2023/11/27 12:23:04 by aschmitt         ###   ########.fr       */
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
	printf("ra\n");
}

void	rotate_b(t_list **b)
{
	rotate(b);
	printf("rb\n");
}

void	rotate_ab(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}
