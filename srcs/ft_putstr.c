/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:53:43 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/24 13:09:46 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i ++;
	return (i);
}

void	ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_error(char *s, t_list **a, t_list **b)
{
	ft_putstr(s);
	if (*a)
		ft_lstclear(a);
	if (*b)
		ft_lstclear(b);
	exit(1);
}
