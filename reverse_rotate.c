/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:25:15 by aschmitt          #+#    #+#             */
/*   Updated: 2023/12/01 17:14:06 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reverse_rotate(t_list **stack)
{
    t_list  *tmp;
    t_list  *runner;

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

void	reverse_rotate_a(t_list **a)
{
	reverse_rotate(a);
	printf("rra\n");
}

void	reverse_rotate_b(t_list **b)
{
	reverse_rotate(b);
	printf("rrb\n");
}

void	reverse_rotate_ab(t_list **a, t_list **b)
{
    reverse_rotate(a);
	reverse_rotate(b);
	printf("rrr\n");
}
