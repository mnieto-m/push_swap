/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:39:44 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/05/28 20:09:13 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_median(t_list *a, int size)
{
    t_list  *copy;
    t_list  *tmp;
    int     rslt;
    int     i;

    i = -1;
    copy = ft_lstcopy_new(a);
    if (!copy)
        return (0);
    ft_quicksort(copy, ft_lstlast(copy), cmp_int);
    tmp = copy;
    while (++i < size / 2)
        tmp = tmp->next;
    rslt = *(int *)(tmp->content);
    ft_lstclear(&copy,free);
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
	t_node		*current;
	int			i;

	stacks = malloc(sizeof(t_stacks) + size * sizeof(t_node));
	if (!stacks)
		automata_error(&a);
	ft_memset(stacks, 0, sizeof(t_stacks));
	stacks->a.size = size;
	stacks->a.name = 'a';
	stacks->a.head = (t_node *)(stacks + 1);
	stacks->b.size = 0;
	stacks->b.name = 'b';
	stacks->b.head = NULL;
	current = stacks->a.head;
	i = -1;
	while (++i < size)
	{
		current->value = get_value(a, i);
		current->next = (i < size - 1) ? current + 1 : stacks->a.head;
		current->prev = (i > 0) ? current - 1 : stacks->a.head + size - 1;
		current++;
	}
	return (stacks);
}
