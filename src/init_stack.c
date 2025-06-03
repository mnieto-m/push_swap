/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:39:44 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/06/03 18:21:22 by mnieto-m         ###   ########.fr       */
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

static void	init_nodes(t_stacks *stacks, t_list *a, int size)
{
	t_node	*current;
	int		i;

	current = stacks->a.head;
	i = 0;
	while (i < size)
	{
		current->value = get_value(a, i);
		if (i == size - 1)
			current->next = stacks->a.head;
		else
			current->next = current + 1;
		if (i == 0)
			current->prev = stacks->a.head + size - 1;
		else
			current->prev = current - 1;
		current++;
		i++;
	}
}

t_stacks	*init_stack(t_list *a, int size)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks) + size * sizeof(t_node));
	if (!stacks)
		automata_error(&a);
	ft_memset(stacks, 0, sizeof(t_stacks));
	stacks->a.head = (t_node *)(stacks + 1);
	stacks->a.size = size;
	stacks->a.name = 'a';
	stacks->b.head = NULL;
	stacks->b.size = 0;
	stacks->b.name = 'b';
	init_nodes(stacks, a, size);
	return (stacks);
}
