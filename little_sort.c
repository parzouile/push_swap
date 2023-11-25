/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:45:02 by aschmitt          #+#    #+#             */
/*   Updated: 2023/11/25 15:44:02 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max(t_list *a)
{
    int i;
    int max;

    i = 0;
    max = a->content;
    a = a->next;
    while (a != NULL)
    {
        if (a->content > max)
        {
            max = a->content;
            i = a->indice;
        }
        a = a->next;
    }
    return (i);
    
}

void    little_sort(t_list **a)
{
    int i_max;

    i_max = find_max(*a);
    if (i_max == 0)
        rotate_a(a);
    else if (i_max == 1)
        reverse_rotate_a(a);
    if (!check_sorted(*a))
        swap_a(a);
}