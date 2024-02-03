/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:17:19 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/24 13:09:05 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	all_diferent(t_list *list)
{
	t_list	*current;
	t_list	*runner;

	if (list == NULL)
		return (1);
	current = list;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->content == runner->content)
				return (0);
			runner = runner->next;
		}
		current = current->next;
	}
	return (1);
}

static int	is_number(char *s)
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

static t_list	*create_list(char **argv)
{
	int		i;
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
	char	**stack;
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

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	else if (argc == 2)
		a = create_list_split(argv[1]);
	else
		a = create_list(argv + 1);
	if (a == NULL)
		ft_error("Error\n", &a, &b);
	execute_command(&a, &b);
	if (check_sorted(a) && b == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	if (a)
		ft_lstclear(&a);
	if (b)
		ft_lstclear(&b);
	return (0);
}
