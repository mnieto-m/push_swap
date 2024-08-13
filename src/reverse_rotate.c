/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:23:07 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/08/13 20:15:07 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_re_rotate(t_list **a)
{
	t_list	*aux;
	t_list	*last_node;
	
	if (*a && (*a)->next)
	{
		last_node = ft_lstlast(*a);
		ft_lstadd_front(a, ft_lstnew(last_node->content));
		aux = ft_lstsecond_last(*a);
		free(ft_lstlast(*a));
		 aux->next = NULL;
	}
}
void rrr(t_list **a,t_list **b)
{
	
}