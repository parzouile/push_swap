/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:10:31 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/24 15:28:33 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i ++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	find_function(char *cmd, t_list **a, t_list **b)
{
	if (!ft_strcmp(cmd, "sa\n"))
		swap_a(a, 0);
	else if (!ft_strcmp(cmd, "sb\n"))
		swap_b(b, 0);
	else if (!ft_strcmp(cmd, "ss\n"))
		swap_ab(a, b, 0);
	else if (!ft_strcmp(cmd, "pa\n"))
		push_a(a, b, 0);
	else if (!ft_strcmp(cmd, "pb\n"))
		push_b(a, b, 0);
	else if (!ft_strcmp(cmd, "ra\n"))
		rotate_a(a, 0);
	else if (!ft_strcmp(cmd, "rb\n"))
		rotate_b(b, 0);
	else if (!ft_strcmp(cmd, "rr\n"))
		rotate_ab(a, b, 0);
	else if (!ft_strcmp(cmd, "rra\n"))
		reverse_rotate_a(a, 0);
	else if (!ft_strcmp(cmd, "rrb\n"))
		reverse_rotate_b(b, 0);
	else if (!ft_strcmp(cmd, "rrr\n"))
		reverse_rotate_ab(a, b, 0);
	else
		return (0);
	return (1);
}

void	execute_command(t_list **a, t_list **b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd != NULL)
	{
		if (!find_function(cmd, a, b))
		{
			free(cmd);
			ft_error("Error\n", a, b);
		}
		free(cmd);
		cmd = get_next_line(0);
	}
}
