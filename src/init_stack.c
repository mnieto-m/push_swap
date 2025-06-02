/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:39:44 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/06/01 23:30:48 by mnieto-m         ###   ########.fr       */
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
	t_stacks	*s;
	t_node		*n;
	int			i;

	s = malloc(sizeof(t_stacks) + size * sizeof(t_node));
	if (!s)
		return (automata_error(&a), NULL);
	ft_memset(s, 0, sizeof(t_stacks));
	s->a.size = size;
	s->a.name = 'a';
	s->a.head = n;
	s->b.size = 0;
	s->b.name = 'b';
	i = 0;
	while (i < size)
	{
		n[i].value = get_value(a, i);
		n[i].next = &n[(i + 1) % size];
		n[i].prev = &n[(i + size - 1) % size];
		i++;
	}
	return (s);
}
