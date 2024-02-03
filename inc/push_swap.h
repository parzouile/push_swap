/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:56:19 by aschmitt          #+#    #+#             */
/*   Updated: 2024/01/26 15:27:58 by aschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

typedef struct s_list
{
	long			content;
	long			index;
	int				cost;
	struct s_list	*target;
	struct s_list	*next;
}					t_list;

int		check_sorted(t_list *stack);
int		len_stack(t_list *stack);
void	update_index(t_list **stack);
t_list	*find_max(t_list *a);
t_list	*find_min(t_list *a);
void	little_sort(t_list **a);
void	big_sort(t_list **a, t_list **b);
void	find_target_a(t_list **a, t_list *b);
void	find_target_b(t_list **a, t_list *b);
void	init_cost(t_list *actual, t_list *other);
t_list	*find_less_cost(t_list *stack);
void	rotate_all(t_list **a, t_list **b, t_list *node);
void	reverse_rotate_all(t_list **a, t_list **b, t_list *node);
void	prepare_push_a(t_list **a, t_list **b);
void	prepare_push_b(t_list **a, t_list **b);
void	ft_error(char *s, t_list **a, t_list **b);

//different rotation
void	swap_a(t_list **a, int print);
void	swap_b(t_list **b, int print);
void	swap_ab(t_list **a, t_list **b, int print);
void	rotate_a(t_list **a, int print);
void	rotate_b(t_list **b, int print);
void	rotate_ab(t_list **a, t_list **b, int print);
void	reverse_rotate_a(t_list **a, int print);
void	reverse_rotate_b(t_list **b, int print);
void	reverse_rotate_ab(t_list **a, t_list **b, int print);
void	push_a(t_list **a, t_list **b, int print);
void	push_b(t_list **a, t_list **b, int print);

//externe
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstnew(long content);
t_list	*ft_lstlast(t_list *lst);
void	ft_putstr(const char *str);

//bonus
void	execute_command(t_list **a, t_list **b);
char	*get_next_line(int fd);
int		ft_strlen(const char *s);
int		check_nl(char *stack);
char	*add_to_stack(char *stack, char *buff);
char	*ft_new_stack(char *buff);

#endif