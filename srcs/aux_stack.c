/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:09:34 by aschmitt          #+#    #+#             */
/*   Updated: 2023/12/01 19:44:33 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_list *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->content < stack->next->content)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
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

void	update_index(t_list **stack)
{
	int		i;
	t_list	*tmp;

	tmp = *stack;
	i = -1;
	while (tmp != NULL)
	{
		tmp->index = ++i;
		tmp = tmp->next;
	}
}

t_list	*find_less_cost(t_list *stack)
{
	t_list	*less_cost;

	less_cost = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->cost < less_cost->cost)
			less_cost = stack;
		stack = stack->next;
	}
	return (less_cost);
}
