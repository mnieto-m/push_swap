/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:23:10 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/08/12 18:01:35 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_rotate(t_list **a)
{
	t_list *aux;
	void *var;
	
	var = (*a)->content;
	aux = (*a)->next;
	if (*a && (*a)->next)
	{
		ft_lstadd_back(a, ft_lstnew(var));
		free(*a);
		*a = aux;
	}
}

void ft_rr(t_list **a,t_list **b)
{
	
}