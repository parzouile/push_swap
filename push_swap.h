#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	long         content;
    long         index;
	int			cost;
	struct s_list	*target;
	struct s_list	*next;
}					t_list;

void	swap_a(t_list **a);
int		len_stack(t_list *stack);
int		check_sorted(t_list *stack);
void	little_sort(t_list **a);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rotate_ab(t_list **a, t_list **b);
void	reverse_rotate_a(t_list **a);
void	reverse_rotate_b(t_list **b);
void	reverse_rotate_ab(t_list **a, t_list **b);
void    update_index(t_list **stack);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	big_sort(t_list **a);
t_list	*find_max(t_list *a);
t_list	*find_less_cost(t_list *a);
void	init_cost(t_list *actual, t_list *other);
void	prepare_push_a(t_list **a, t_list **b, t_list *node);
void	prepare_push_b(t_list **a, t_list **b, t_list *node);
void	prepare_b(t_list **a, t_list *node, long size_a);
void	prepare_a(t_list **a, t_list *node, long size_a);
void	reverse_rotate_all(t_list **a, t_list **b, t_list *node);
void	rotate_all(t_list **a, t_list **b, t_list *node);


long	ft_atoi(const char *str);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstnew(long content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
char	**ft_split(char const *s, char c);



void    print_stack(t_list *a);

#endif