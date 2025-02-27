/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:40:45 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/02/22 17:26:29 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	head_to_bottom(t_stack *stack, t_ord *ord)
{
	int	rots;

	rots = (ord->top.loc + 1) % stack->size;
	if (rots < stack->size - rots)
	{
		while (rots--)
			write(1, (char []){'r', stack->name, '\n'}, 3);
	}
	else
	{
		rots = stack->size - rots;
		while (rots--)
			write(1, (char []){'r', 'r', stack->name, '\n'}, 4);
	}
	stack->head = ord->top.node->next;
	ord->top.loc = stack->size - 1;
}

bool	stack_sorted(t_stack *stack, t_ord *ord, bool relative)
{
	t_node	*cur;
	int		i;

	if (relative)
	{
		set_top(stack, ord);
		cur = ord->top.node->next;
	}
	else
		cur = stack->head;
	i = stack->size;
	while (--i)
	{
		if (ord->gt(cur->value, cur->next->value))
			return (0);
		cur = cur->next;
	}
	return (1);
}
