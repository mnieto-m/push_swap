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
int	ft_lstsize(t_list *lst);

#endif