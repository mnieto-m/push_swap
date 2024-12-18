/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:39:14 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/12/18 17:06:08 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	automata_error(t_list **a)
{
	printf("Error\n");
	ft_lstclear(a, free);
	exit(EXIT_FAILURE);
}