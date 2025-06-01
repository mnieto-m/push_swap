/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:39:14 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/06/01 23:34:46 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	automata_error(t_list **a)
{
	ft_putstr_fd("error\n", 2);
	ft_lstclear(a, free);
	exit(EXIT_FAILURE);
}

void	success_order(t_list **a)
{
	ft_lstclear(a, free);
	exit(EXIT_SUCCESS);
}

void	fail_malloc(t_list **a)
{
	ft_lstclear(a, free);
	exit(EXIT_FAILURE);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	current = stack->head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	stack->head = NULL;
}

void	free_stacks(t_stacks *stacks)
{
	if (&stacks->a)
		free_stack(&stacks->a);
	if (&stacks->b)
		free_stack(&stacks->b);
	free(stacks);
}
