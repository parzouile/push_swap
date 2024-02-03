/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:35:47 by aschmitt          #+#    #+#             */
/*   Updated: 2023/12/01 19:59:43 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target_a(t_list **a, t_list *b)
{
	t_list	*current_a;
	t_list	*current_b;
	t_list	*closest_smaller;
	t_list	*max;

	current_a = *a;
	max = find_max(b);
	while (current_a != NULL)
	{
		current_b = b;
		closest_smaller = NULL;
		while (current_b != NULL)
		{
			if (current_b->content < current_a->content)
				if (closest_smaller == NULL
					|| current_b->content > closest_smaller->content)
					closest_smaller = current_b;
			current_b = current_b->next;
		}
		if (closest_smaller != NULL)
			current_a->target = closest_smaller;
		else
			current_a->target = max;
		current_a = current_a->next;
	}
}

void	find_target_b(t_list **a, t_list *b)
{
	t_list	*current_a;
	t_list	*current_b;
	t_list	*closest_larger;
	t_list	*min;

	current_a = *a;
	min = find_min(b);
	while (current_a != NULL)
	{
		current_b = b;
		closest_larger = NULL;
		while (current_b != NULL)
		{
			if (current_b->content > current_a->content)
				if (closest_larger == NULL
					|| current_b->content < closest_larger->content)
					closest_larger = current_b;
			current_b = current_b->next;
		}
		if (closest_larger != NULL)
			current_a->target = closest_larger;
		else
			current_a->target = min;
		current_a = current_a->next;
	}
}

void	init_cost(t_list *actual, t_list *other)
{
	long	size_actual;
	long	size_other;

	size_actual = len_stack(actual);
	size_other = len_stack(other);
	while (actual)
	{
		actual->cost = actual->index;
		if (actual->index > (size_actual / 2))
			actual->cost = size_actual - (actual->index);
		if (actual->target->index <= (size_other / 2))
			actual->cost += actual->target->index;
		else
			actual->cost += size_other - (actual->target->index);
		actual = actual->next;
	}
}
