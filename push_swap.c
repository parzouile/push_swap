/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:34:01 by aschmitt          #+#    #+#             */
/*   Updated: 2023/11/21 18:37:50 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_list(int size, char **stack)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		
	}
	
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return (1);
    if (!check_list(argc - 1, argv + 1))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	
	return (0);
}
