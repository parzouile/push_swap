/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:07:48 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/24 13:07:52 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_nl(char *stack)
{
	size_t	i;

	i = -1;
	if (!stack)
		return (-1);
	while (stack[++i])
		if (stack[i] == '\n')
			return (i);
	return (-1);
}

char	*add_to_stack(char *stack, char *buff)
{
	char	*result;
	size_t	i;
	size_t	a;

	a = -1;
	i = -1;
	result = malloc(sizeof(char) * (ft_strlen(stack) + ft_strlen(buff) + 1));
	if (!result)
		return (NULL);
	while (stack[++i])
		result[i] = stack[i];
	while (buff[++a])
		result[i++] = buff[a];
	result[i] = 0;
	free(stack);
	return (result);
}

char	*ft_new_stack(char *buff)
{
	char	*result;
	size_t	i;

	i = -1;
	result = malloc(sizeof(char) * (ft_strlen(buff) + 1));
	if (!result)
		return (NULL);
	while (buff[++i])
		result[i] = buff[i];
	result[i] = 0;
	return (result);
}
