/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:07:02 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/07/30 15:06:02 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list		*a;
	t_stacks	*s;
	int			i;

	i = 1;
	a = NULL;
	if (argc < 2)
		return (0);
	while (i < argc)
		automata_parse(argv[i++], &a);
	if (ft_orded(a) == TRUE)
		success_order(a);
	s = init_stack(a, ft_lstsize(a));
	if (!s)
		ft_lstclear(&a, free);
	s->median = get_median(a, s->size);
	ft_lstclear(&a, free);
	if (s->size == 2)
		sort_2(&s->a);
	else if (s->size == 3)
		sort_3(&s->a, &(t_ord){greater, {NULL, 0}}, 0);
	else
		turk(s, s->median, s->size);
	free(s);
	return (0);
}
