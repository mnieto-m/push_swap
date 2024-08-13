/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:23:13 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/08/12 18:02:24 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void ss(t_list **a, t_list **b)
{
	void	*var1;
	void	*var2;
	
	if(ft_lstsize(*a) > 1)
	{
		var1 = (*a)->content;
		var2 = (*a)->next->content;
		(*a)->content = var2;
		(*a)->next->content = var1;
	}
	
	if(ft_lstsize(*b) > 1)
	{
		var1 = (*b)->content;
		var2 = (*b)->next->content;
		(*b)->content = var2;
		(*b)->next->content = var1;
	}
}
