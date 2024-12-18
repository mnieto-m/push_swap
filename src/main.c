/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:07:02 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/12/18 17:12:42 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	int		i;

	i = 1;
	a = NULL;
	while (i >= 1 && i < argc)
		automata_parse(argv[i++], &a);
	/* printList(a); */
	ft_lstclear(&a, free);
	return (0);
}
