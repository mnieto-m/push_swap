/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:23:13 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/06/03 17:19:18 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
