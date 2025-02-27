/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_best.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:40:33 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/02/22 16:54:28 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_rots(t_stack *src, t_stack *dst, t_ord *ord, t_rated_node *rnd)
{
	t_rated_node	cur;

	cur.src_nd.node = src->head;
	cur.src_nd.loc = 0;
	get_tg(src, dst, &cur, ord);
	if (cur.src_nd.loc < 0)
		cur.src_nd.loc += src->size;
	*rnd = cur;
	while (++cur.src_nd.loc < src->size)
	{
		cur.src_nd.node = cur.src_nd.node->next;
		get_tg(src, dst, &cur, ord);
		if (cur.rate < rnd->rate)
			*rnd = cur;
		if (cur.src_nd.loc < 0)
			cur.src_nd.loc += src->size;
	}
}

void	get_tg(t_stack *src, t_stack *dst, t_rated_node *rnd, t_ord *ord)
{
	if (out_of_bounds(rnd->src_nd.node->value, ord))
	{
		rnd->dst_nd.node = ord->top.node->next;
		rnd->dst_nd.loc = (ord->top.loc + 1) % (dst->size);
	}
	else
	{
		rnd->dst_nd.node = dst->head;
		rnd->dst_nd.loc = 0;
		while (ord->gt(rnd->src_nd.node->value, rnd->dst_nd.node->value))
		{
			rnd->dst_nd.node = rnd->dst_nd.node->next;
			rnd->dst_nd.loc++;
		}
		while (ord->gt(rnd->dst_nd.node->value, rnd->src_nd.node->value))
		{
			if (ord->gt(rnd->src_nd.node->value, rnd->dst_nd.node->prev->value))
				break ;
			rnd->dst_nd.node = rnd->dst_nd.node->prev;
			rnd->dst_nd.loc--;
		}
		rnd->dst_nd.loc = ft_mod(rnd->dst_nd.loc, dst->size);
	}
	get_cost(src, dst, rnd);
}

void	get_cost(t_stack *src, t_stack *dst, t_rated_node *rnd)
{
	int	src_nd_loc;
	int	dst_nd_loc;

	src_nd_loc = rnd->src_nd.loc;
	dst_nd_loc = rnd->dst_nd.loc;
	rnd->rate = ft_maxint(src_nd_loc, dst_nd_loc);
	if (rnd->rate > ft_maxint(src->size - src_nd_loc, dst->size - dst_nd_loc))
	{
		rnd->rate = ft_maxint(src->size - src_nd_loc, dst->size - dst_nd_loc);
		rnd->src_nd.loc = src_nd_loc - src->size;
		rnd->dst_nd.loc = dst_nd_loc - dst->size;
	}
	if (rnd->rate > src_nd_loc + (dst->size - dst_nd_loc))
	{
		rnd->rate = src_nd_loc + (dst->size - dst_nd_loc);
		rnd->src_nd.loc = src_nd_loc;
		rnd->dst_nd.loc = dst_nd_loc - dst->size;
	}
	if (rnd->rate > (src->size - src_nd_loc) + dst_nd_loc)
	{
		rnd->rate = (src->size - src_nd_loc) + dst_nd_loc;
		rnd->src_nd.loc = src_nd_loc - src->size;
		rnd->dst_nd.loc = dst_nd_loc;
	}
}

bool	out_of_bounds(int value, t_ord *ord)
{
	if (ord->gt(value, ord->top.node->value))
		return (true);
	if (ord->gt(ord->top.node->next->value, value))
		return (true);
	return (false);
}

void	push_stack(t_stack *src, t_stack *dst, t_ord *ord, int limit)
{
	t_rated_node	rots;

	set_top(dst, ord);
	while (src->size > limit)
	{
		get_rots(src, dst, ord, &rots);
		src->head = rots.src_nd.node;
		dst->head = rots.dst_nd.node;
		ord->top.loc = ft_mod(ord->top.loc - rots.dst_nd.loc, dst->size);
		print_rots(&rots, src);
		push(src, dst, true);
		if (ord->gt(dst->head->value, ord->top.node->value))
			ord->top = (t_loc_node){dst->head, 0};
		else
			ord->top.loc = (ord->top.loc + 1) % dst->size;
	}
}
