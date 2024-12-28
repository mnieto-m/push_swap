/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:07:02 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/12/21 17:46:24 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	int		i;
	int median;
	int size;
	t_stacks	*s;

	i = 1;
	a = NULL;
	if (argc < 2)
		return(0);
	while(i >= 1 && i < argc)
		automata_parse(argv[i++], &a);
	size = ft_lstsize(a);
	s = init_stack(a,size, &median);		
	ft_lstclear(&a, free);
	if (size == 2)
		sort_2(&s->a);
	else if (size == 3)
		sort_3(&s->a, &(t_ord){greater, {NULL, 0}}, 0);
	else
		turk(s, median, size);
	free(s);
	return (0);
}
