/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:39:51 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/02/15 12:23:16 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		calc_rots(t_rated_node *rnd);
static void	case_pp(t_rated_node *rnd);
static void	case_nn(t_rated_node *rnd);

void	calc_rots(t_rated_node *rnd)
{
	if (rnd->src_nd.loc * rnd->dst_nd.loc < 0)
		rnd->rate = 0;
	else if (rnd->src_nd.loc + rnd->dst_nd.loc > 0)
		case_pp(rnd);
	else
		case_nn(rnd);
}

static void	case_pp(t_rated_node *rnd)
{
	if (rnd->src_nd.loc >= rnd->dst_nd.loc)
	{
		rnd->rate = 1;
		rnd->src_nd.loc -= rnd->dst_nd.loc;
	}
	else
	{
		rnd->rate = 2;
		rnd->dst_nd.loc -= rnd->src_nd.loc;
	}
}

static void	case_nn(t_rated_node *rnd)
{
	if (rnd->src_nd.loc <= rnd->dst_nd.loc)
	{
		rnd->rate = -1;
		rnd->src_nd.loc -= rnd->dst_nd.loc;
	}
	else
	{
		rnd->rate = -2;
		rnd->dst_nd.loc -= rnd->src_nd.loc;
	}
}
