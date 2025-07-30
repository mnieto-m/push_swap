/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:23:13 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/07/30 15:05:47 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

t_list	*ft_lstcopy_new(t_list *lst)
{
	t_list	*new_list;
	void	*content_copy;

	if (!lst)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content_copy = malloc(sizeof(int));
		if (!content_copy)
			return (NULL);
		*(int *)content_copy = *(int *)lst->content;
		ft_lstadd_back(&new_list, ft_lstnew(content_copy));
		lst = lst->next;
	}
	return (new_list);
}

int	get_median(t_list *a, int size)
{
	t_list	*copy;
	t_list	*tmp;
	int		rslt;
	int		i;

	i = -1;
	copy = ft_lstcopy_new(a);
	if (!copy)
		automata_error(&a);
	ft_quicksort(copy, ft_lstlast(copy), cmp_int);
	tmp = copy;
	while (++i < size / 2)
		tmp = tmp->next;
	rslt = *(int *)(tmp->content);
	ft_lstclear(&copy, free);
	return (rslt);
}
