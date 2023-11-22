/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:34:01 by aschmitt          #+#    #+#             */
/*   Updated: 2023/11/22 11:08:56 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] && (s[i] == '-' || s[i] == '+'))
		i ++;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i ++;
		else
			return (0);
	}
	return (i > 0);
	
}

static t_list *create_list(int size, char **stack)
{
	int	i;
	int a;
	t_list	*res;
	t_list	*node;

	i = -1;
	res = NULL;
	while (++i < size)
	{
		node = ft_lstnew(ft_atoi(stack[i]));
		if (!is_number(stack[i]) || node == NULL)
		{
			ft_lstclear(&res);
			free(node);
			return (res);
		}
		ft_lstadd_back(&res, node);
	}
	return (res);
	
}

int main(int argc, char **argv)
{
	t_list *a;
	
    if (argc == 1)
        return (1);
	a = create_list(argc - 1, argv + 1);
    if (a == NULL)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	print_stack(a);
	ft_lstclear(&a);
	return (0);
}
