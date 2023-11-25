/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:01:00 by aschmitt          #+#    #+#             */
/*   Updated: 2023/11/25 15:08:59 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	long	tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
}

void	swap_a(t_list **a)
{
	swap(a);
	printf("sa\n");
}

void	swap_b(t_list **b)
{
	swap(b);
	printf("sb\n");
}

int	len_stack(t_list *stack)
{
	int	i;
	
	i = 0;
	while (stack != NULL)
	{
		i ++;
		stack = stack->next;
	}
	return (i);
}
