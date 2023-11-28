/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:34:01 by aschmitt          #+#    #+#             */
/*   Updated: 2023/11/28 16:20:40 by aschmitt         ###   ########.fr       */
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

int	all_diferent(t_list *list)
{
	t_list *current;
	t_list *runner;

	if (list == NULL)
		return (1);
	
	current = list;
	while (current != NULL) 
	{
		runner = current->next;
		while (runner != NULL) 
		{
			if (current->content == runner->content)
				return 0;
			runner = runner->next;
		}
		current = current->next;
	}
	return (1);
}


static t_list *create_list(char **argv)
{
	int	i;
	t_list	*res;
	t_list	*node;

	i = -1;
	res = NULL;
	while (argv[++i])
	{
		node = ft_lstnew(ft_atoi(argv[i]));
		if (!is_number(argv[i]) || node == NULL || node->content == 2147483648)
		{
			ft_lstclear(&res);
			free(node);
			return (res);
		}
		node->index = i;
		ft_lstadd_back(&res, node);
	}
	if (all_diferent(res))
		return (res);
	ft_lstclear(&res);
	return (res);
	
}

static t_list	*create_list_split(char *s)
{
	char **stack;
	int		i;
	t_list	*res;

	stack = ft_split(s, ' ');
	if (stack == NULL)
		return (NULL);
	res = create_list(stack);
	i = -1;
	while (stack[++i])
	{
		free(stack[i]);
	}
	free(stack);
	return (res);
}
	
int main(int argc, char **argv)
{
	t_list *a;

	if (argc == 1)
		return (1);
	else if (argc == 2)
		a = create_list_split(argv[1]);
	else
		a = create_list(argv + 1);
	if (a == NULL)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!check_sorted(a))
	{
		if (len_stack(a) == 2)
			swap_a(&a);
		else if (len_stack(a) == 3)
			little_sort(&a);
		else
			big_sort(&a);
	}
	print_stack(a);
	ft_lstclear(&a);
	return (0);
}
