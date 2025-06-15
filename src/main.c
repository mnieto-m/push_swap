/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:07:02 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/06/15 13:50:09 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list		*a;
	t_stacks	*s;
	int			i;
	int			size;
	int			median;

	i = 1;
	a = NULL;
	if (argc < 2)
		return (0);
	while (i < argc)
		automata_parse(argv[i++], &a);
	if( ft_orded(a) == TRUE)
		success_order(a);
	size = ft_lstsize(a);
	median = get_median(a, size);
	s = init_stack(a, size);
	if (!s)
		ft_lstclear(&a, free);
	ft_lstclear(&a, free);	
	if (size == 2)
		sort_2(&s->a);
	else if (size == 3)
		sort_3(&s->a, &(t_ord){greater, {NULL, 0}}, 0);
	else
		turk(s, median, size);
	return (0);
}
