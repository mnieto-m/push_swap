#include "prueba.h"

void ft_swap(t_list **a)
{
	t_list	*first;
	t_list	*second ;
	void 	*var;
	
	if(ft_lstsize(*a) > 1)
	{
		first = *a;
		second = (*a)->next;
		var = (*a)->content;
		(*a)->content = second->content;
		(*a)->next->content = var;
	}
}
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}