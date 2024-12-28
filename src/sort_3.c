/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:40:54 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/12/28 17:46:08 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void		sort_2(t_stack *stack);
void		sort_3(t_stack *stack, t_ord *ord, bool relative);
void		turk(t_stacks *s, int median, int size);
static void	push_halves(t_stacks *s, int median, int size);

void	sort_2(t_stack *stack)
{
	if (stack->head->value > stack->head->next->value)
		rot(stack, true);
}

void	sort_3(t_stack *stack, t_ord *ord, bool relative)
{
	if (!stack_sorted(stack, ord, 1))
	{
		swap(stack, 1);
		if (ord->top.loc == 0)
			ord->top.loc++;
		else if (ord->top.loc == 1)
			ord->top.loc--;
	}
	if (!relative)
		head_to_bottom(stack, ord);
}

void	turk(t_stacks *s, int median, int size)
{
	t_ord	as;
	t_ord	des;

	as = (t_ord){greater, {NULL, 0}};
	des = (t_ord){lower, {NULL, 0}};
	if (stack_sorted(&s->a, &as, true))
		return (head_to_bottom(&s->a, &as));
	if (size <= 5)
	{
		push(&s->a, &s->b, true);
		if (size == 5)
			push(&s->a, &s->b, true);
	}
	else
		push_halves(s, median, size);
	sort_3(&s->a, &as, 1);
	push_stack(&s->b, &s->a, &as, 0);
	head_to_bottom(&s->a, &as);
}

static void	push_halves(t_stacks *s, int median, int size)
{
	while (s->b.size < size / 2)
	{
		if (s->a.head->value < median)
			push(&s->a, &s->b, 1);
		else
			rot(&s->a, 1);
	}
	while (s->a.size > 3)
		push(&s->a, &s->b, 1);
}
