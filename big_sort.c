/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:28:37 by aschmitt          #+#    #+#             */
/*   Updated: 2023/11/29 12:47:24 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list *a)
{
	t_list	*min;

	min = a;
	a = a->next;
	while (a != NULL)
	{
		if (a->content < min->content)
			min = a;
		a = a->next;
	}
	return (min);
}

void	finish_sort(t_list **a)
{
	t_list	*min;

	min = find_min(*a);
	if (min->index  <= len_stack(*a) / 2)
		while ((*a)->content != min->content)
			rotate_a(a);
	else
		while ((*a)->content != min->content)
			reverse_rotate_a(a);
}

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
				if (closest_smaller == NULL || current_b->content > closest_smaller->content) 
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
                if (closest_larger == NULL || current_b->content < closest_larger->content) 
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

void	big_sort(t_list **a)
{
	t_list	*b;
	int		size;
	
	b = NULL;
	size = len_stack(*a);
	push_b(a, &b);
	if (--size > 3 && check_sorted(*a )== 0)
		push_b(a, &b);
	while (--size > 3 && check_sorted(*a) == 0)
	{
		find_target_a(a, b);
		init_cost(*a, b);
		prepare_push_a(a, &b, find_less_cost(*a));
	}
	if (check_sorted(*a) == 0)
		little_sort(a);
	while (b)
	{
		find_target_b(&b, *a);
		init_cost(b, *a);
		prepare_push_b(a, &b, find_less_cost(b));
	}
	finish_sort(a);
}
