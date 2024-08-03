#include "prueba.h"

void ft_swap(t_list **a)
{
	void	*var2;
	void 	*var1;
	
	if(ft_lstsize(*a) > 1)
	{
		var1 = (*a)->content;
		var2 = (*a)->next->content;
		(*a)->content = var2;
		(*a)->next->content = var1;
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