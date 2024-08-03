/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:23:13 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/08/03 18:16:45 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include "push_swap.h"

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

void ss(t_lis **a, t_list **b)
{
	
}
