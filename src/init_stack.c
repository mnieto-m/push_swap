/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:39:44 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/01 01:00:22 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	fill_stack_nodes(t_list *a, t_node *nodes, int size)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = nodes;
	while (i < size && a)
	{
		curr->value = *(int *)a->content;
		if (i > 0)
			curr->prev = curr - 1;
		if (i < size - 1)
			curr->next = curr + 1;
		else
			curr->next = nodes;
		a = a->next;
		curr++;
		i++;
	}
	nodes->prev = curr - 1;
}

t_stacks	*init_stack(t_list *a, int size)
{
	t_stacks	*st;

	st = malloc(sizeof(t_stacks) + size * sizeof(t_node));
	if (!st)
		automata_error(&a);
	ft_bzero(st, sizeof(t_stacks) + size * sizeof(t_node));
	st->size = size;
	st->a.size = size;
	st->a.head = st->nodes;
	st->a.name = 'a';
	st->b.size = 0;
	st->b.head = NULL;
	st->b.name = 'b';
	fill_stack_nodes(a, st->nodes, size);
	return (st);
}
