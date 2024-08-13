/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:45:51 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/08/13 18:26:42 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void pa(t_list **a, t_list **b)
{
	t_list *aux;
	
	if((*b))
	{
		ft_lstadd_front(b,ft_lstnew((*a)->content));
		aux = (*a)->next;
		free(*a);
		*a = aux;
	}
}
void pb(t_list **a, t_list **b)
{
	if((*b))
	{
		
	}
}