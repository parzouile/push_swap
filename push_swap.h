#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	long         content;
    long         indice;
	struct s_list	*next;
}					t_list;

long	ft_atoi(const char *str);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstnew(long content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
char	**ft_split(char const *s, char c);



void    print_stack(t_list *a);

#endif