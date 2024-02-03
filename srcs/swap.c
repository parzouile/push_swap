/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:14:56 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/24 15:20:11 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	long	tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
}

void	swap_a(t_list **a, int print)
{
	swap(a);
	if (print)
		ft_putstr("sa\n");
}

void	swap_b(t_list **b, int print)
{
	swap(b);
	if (print)
		ft_putstr("sb\n");
}

void	swap_ab(t_list **a, t_list **b, int print)
{
	swap(a);
	swap(b);
	if (print)
		ft_putstr("ss\n");
}
