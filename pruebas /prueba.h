#ifndef PRUEBA_H
# define PRUEBA_H

# include <stdint.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
void ft_swap(t_list **a);
void ft_rotate(t_list **a);
int	ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
void printList(t_list *lst);
void	ft_lstclear(t_list **lst, void (*del)(void *));
#endif