/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:18:01 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/24 13:29:17 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*runner;

	tmp = ft_lstlast(*stack);
	runner = *stack;
	while (runner != NULL && runner->next != NULL && runner->next->next != NULL)
	{
		runner = runner->next;
	}
	if (runner != NULL)
		runner->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	update_index(stack);
}

void	reverse_rotate_a(t_list **a, int print)
{
	if (*a == NULL)
		return ;
	reverse_rotate(a);
	if (print)
		ft_putstr("rra\n");
}

void	reverse_rotate_b(t_list **b, int print)
{
	if (*b == NULL)
		return ;
	reverse_rotate(b);
	if (print)
		ft_putstr("rrb\n");
}

void	reverse_rotate_ab(t_list **a, t_list **b, int print)
{
	if (*a == NULL || *b == NULL)
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		ft_putstr("rrr\n");
}
