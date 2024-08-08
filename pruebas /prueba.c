#include "prueba.h"

void ft_rotate(t_list **a)
{
	t_list *aux;
	void *var = NULL;
	
	if (*a && (*a)->next)
	{
		var = (*a)->content;
		aux = (*a)->next;
		ft_lstadd_back(a, ft_lstnew(var));
		free(*a);
		*a = aux;
	}
}
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	aux = *lst;
	while (aux)
	{
		aux = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
}
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && lst->content && del)
		del(lst->content);
	if (lst)
		free(lst);
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
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
t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (0);
}