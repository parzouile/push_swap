/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:15:06 by aschmitt          #+#    #+#             */
/*   Updated: 2023/11/28 22:43:46 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			actual->cost = size_actual - actual->index;
		if (actual->target->index > (size_other / 2))
			actual->cost += actual->target->index;
		else
			actual->cost += size_other - actual->target->index;
		actual = actual->next;
	}
}
