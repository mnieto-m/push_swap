/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:39:44 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/12/21 18:28:06 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_quicksort(copy, 0, *size - 1)
{


}
get_median(t_list *a, int size)
{
	t_list 	*copy;

	copy = ft_lstmap();
}
void init_stack(t_list *a, int size, int *median)
{
	t_stacks	*stacks;
	
	median = get_median(a);
	stacks = malloc(sizeof (t_stacks) + size * sizeof (t_node));
	if (stacks == NULL)
		return (NULL);
	stacks->a.size = size;
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
