/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:07:02 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/06/03 17:58:40 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	aux_order(int size, int median, t_stacks *s)
{
	t_ord	ord;

	ord.gt = greater;
	ord.top.node = s->a.head;
	ord.top.loc = 0;
	if (size == 2)
		sort_2(&s->a);
	else if (size == 3)
	{
		sort_3(&s->a, &ord, 0);
	}
	else
		turk(s, median, size);
}

int	main(int argc, char **argv)
{
	t_list		*a;
	t_stacks	*s;
	int			size;
	int			i;
	int			median;

	i = 1;
	a = NULL;
	if (argc < 2)
		return (0);
	while (i < argc)
		automata_parse(argv[i++], &a);
	if (ft_orded(a) == TRUE)
		success_order(&a);
	size = ft_lstsize(a);
	median = get_median(a, size);
	s = init_stack(a, size);
	if (!s)
		fail_malloc(&a);
	aux_order(size, median, s);
	ft_lstclear(&a, free);
	free(s);
	return (0);
}
