/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rots_movs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:40:40 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/12/28 17:40:42 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	rot(t_stack *stack, bool print)
{
	stack->head = stack->head->next;
	if (print)
		write(1, (char []){'r', stack->name, '\n'}, 3);
}

void	rrot(t_stacks *stacks, bool print)
{
	rot(&stacks->a, false);
	rot(&stacks->b, false);
	if (print)
		write(1, (char []){'r', 'r', '\n'}, 3);
}

void	rev(t_stack *stack, bool print)
{
	stack->head = stack->head->prev;
	if (print)
		write(1, (char []){'r', 'r', stack->name, '\n'}, 4);
}

void	rrev(t_stacks *stacks, bool print)
{
	rev(&stacks->a, false);
	rev(&stacks->b, false);
	if (print)
		write(1, (char []){'r', 'r', 'r', '\n'}, 4);
}
