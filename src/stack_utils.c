/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:40:45 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/02/15 12:24:11 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		head_to_bottom(t_stack *stack, t_ord *ord);
t_stacks	*init_stacks(int arr[], int nbs);
bool		stack_sorted(t_stack *stack, t_ord *ord, bool relative);

t_stacks	*init_stacks(int arr[], int nbs)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof (t_stacks) + nbs * sizeof (t_node));
	if (stacks == NULL)
		return (NULL);
	stacks->a.size = nbs;
	stacks->a.head = stacks->nodes;
	stacks->a.name = 'a';
	stacks->b.size = 0;
	stacks->b.head = NULL;
	stacks->b.name = 'b';
	while (--nbs)
	{
		stacks->a.head->value = *(arr++);
		stacks->a.head->next = stacks->a.head + 1;
		(stacks->a.head + 1)->prev = stacks->a.head;
		stacks->a.head++;
	}
	stacks->a.head->value = *arr;
	stacks->a.head->next = stacks->nodes;
	stacks->nodes->prev = stacks->a.head;
	stacks->a.head = stacks->nodes;
	return (stacks);
}

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
