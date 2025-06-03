/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:39:44 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/06/03 17:25:27 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_median(t_list *a, int size)
{
	t_list	*copy;
	t_list	*tmp;
	int		rslt;
	int		i;

	i = -1;
	copy = ft_lstcopy_new(a);
	if (!copy)
		return (0);
	ft_quicksort(copy, ft_lstlast(copy), cmp_int);
	tmp = copy;
	while (++i < size / 2)
		tmp = tmp->next;
	rslt = *(int *)(tmp->content);
	ft_lstclear(&copy, free);
	return (rslt);
}

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
	memset(stacks, 0, sizeof(t_stacks));
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
