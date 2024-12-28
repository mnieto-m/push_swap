/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:40:05 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/12/28 17:40:06 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "pswap.h"

bool	greater(int a, int b)
{
	return (a > b);
}

bool	lower(int a, int b)
{
	return (a < b);
}

void	set_top(t_stack *stack, t_ord *ord)
{
	t_loc_node	cur;

	cur = (t_loc_node){stack->head, 0};
	ord->top = cur;
	while (++cur.loc < stack->size)
	{
		cur.node = cur.node->next;
		if (ord->gt(cur.node->value, ord->top.node->value))
			ord->top = cur;
	}
}
