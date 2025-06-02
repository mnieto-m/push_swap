/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_movs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:40:16 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/06/01 23:31:48 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dst, bool print)
{
	t_node	*node;

	if (src->size > 0)
	{
		src->head->next->prev = src->head->prev;
		src->head->prev->next = src->head->next;
		node = src->head;
		if (src->size-- > 1)
			src->head = src->head->next;
		else
			src->head = NULL;
		if (dst->size++ > 0)
		{
			node->prev = dst->head->prev;
			node->prev->next = node;
			node->next = dst->head;
			node->next->prev = node;
		}
		else
			*node = (t_node){node->value, node, node};
		dst->head = node;
	}
	if (print)
		write(1, (char []){'p', dst->name, '\n'}, 3);
}

void	swap(t_stack *stack, bool print)
{
	if (stack->size > 2)
	{
		stack->head->prev->next = stack->head->next;
		stack->head->next->prev = stack->head->prev;
		stack->head->next = stack->head->next->next;
		stack->head->next->prev = stack->head;
		stack->head->prev->next->next = stack->head;
		stack->head->prev = stack->head->prev->next;
	}
	if (stack->size > 1)
		stack->head = stack->head->prev;
	if (print)
		write(1, (char []){'s', stack->name, '\n'}, 3);
}

void	sswap(t_stacks *stacks, bool print)
{
	swap(&stacks->a, false);
	swap(&stacks->b, false);
	if (print)
		write(1, (char []){'s', 's', '\n'}, 3);
}
