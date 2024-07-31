#include "prueba.h"

void ft_swap(t_list **a)
{
	t_list	*frist = malloc(sizeof(t_list));
	t_list	*second = malloc(sizeof(t_list));
	
	if(ft_lstsize(*a) >= 2)
	{
		frist = *a;
		second = (*a)->next;
		(*a)->content = frist->content;
		(*a)->next->content = second->content;
	}
}
int main()
{
	t_list *a;

	a = malloc(sizeof(t_list));
	a->content = "Node 1";
	a->next = NULL;
		
	ft_swap(&a);
	
	while (a != NULL) {
		printf("%s\n", (char *)(a->content));
		a = a->next;
	}
	return 0;
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
