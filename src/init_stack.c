/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:39:44 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/07/30 16:26:25 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

static int	get_value(t_list *a, int indx)
{
	while (a->next && indx--)
	{
		a = a->next;
	}
	return (*(int *)(a->content));
}

t_stacks	*init_stack(t_list *a, int size)
{
	t_stacks	*stacks;

	stacks = malloc((sizeof(t_stacks)) + size * sizeof(t_node));
	if (stacks == NULL)
		automata_error(&a);
	ft_bzero(stacks, sizeof(t_stacks) + size * sizeof(t_node));
	stacks->size = size;
	stacks->a.size = size;
	stacks->a.head = stacks->nodes;
	stacks->a.name = 'a';
	stacks->b.size = 0;
	stacks->b.head = NULL;
	stacks->b.name = 'b';
	while (--size)
	{
		stacks->a.head->value = get_value(a, size);
		stacks->a.head->next = stacks->a.head + 1;
		(stacks->a.head + 1)->prev = stacks->a.head;
		stacks->a.head++;
	}
	stacks->a.head->next = stacks->nodes;
	stacks->nodes->prev = stacks->a.head;
	stacks->a.head = stacks->nodes;
	return (stacks);
}
