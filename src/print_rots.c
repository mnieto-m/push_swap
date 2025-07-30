/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rots.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:40:25 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/07/30 12:58:20 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

static void	print_case_0(t_rated_node *rots, char src)
{
	char	dst;
	char	*r_src;
	char	*rr_src;
	char	*r_dst;
	char	*rr_dst;

	dst = ((src == 'a') * 'b') + ((src != 'a') * 'a');
	r_src = (char []){'r', src, '\n'};
	rr_src = (char []){'r', 'r', src, '\n'};
	r_dst = (char []){'r', dst, '\n'};
	rr_dst = (char []){'r', 'r', dst, '\n'};
	if (rots->src_nd.loc >= 0)
	{
		while (rots->src_nd.loc--)
			write(1, r_src, 3);
		while (rots->dst_nd.loc++)
			write(1, rr_dst, 4);
	}
	else
	{
		while (rots->src_nd.loc++)
			write(1, rr_src, 4);
		while (rots->dst_nd.loc--)
			write(1, r_dst, 3);
	}
}

static void	print_case_pp(t_rated_node *rots, char src)
{
	char	dst;
	char	*r_src;
	char	*r_dst;

	dst = ((src == 'a') * 'b') + ((src != 'a') * 'a');
	r_src = (char []){'r', src, '\n'};
	r_dst = (char []){'r', dst, '\n'};
	if (rots->rate == 1)
	{
		while (rots->dst_nd.loc--)
			write(1, "rr\n", 3);
		while (rots->src_nd.loc--)
			write(1, r_src, 3);
	}
	else if (rots->rate == 2)
	{
		while (rots->src_nd.loc--)
			write(1, "rr\n", 3);
		while (rots->dst_nd.loc--)
			write(1, r_dst, 3);
	}
}

static void	print_case_nn(t_rated_node *rots, char src)
{
	char	dst;
	char	*rr_src;
	char	*rr_dst;

	dst = ((src == 'a') * 'b') + ((src != 'a') * 'a');
	rr_src = (char []){'r', 'r', src, '\n'};
	rr_dst = (char []){'r', 'r', dst, '\n'};
	if (rots->rate == -1)
	{
		while (rots->dst_nd.loc++)
			write(1, "rrr\n", 4);
		while (rots->src_nd.loc++)
			write(1, rr_src, 4);
	}
	else if (rots->rate == -2)
	{
		while (rots->src_nd.loc++)
			write(1, "rrr\n", 4);
		while (rots->dst_nd.loc++)
			write(1, rr_dst, 4);
	}
}

void	print_rots(t_rated_node *rots, t_stack *src)
{
	calc_rots(rots);
	if (rots->rate == 0)
		print_case_0(rots, src->name);
	else if (rots->rate > 0)
		print_case_pp(rots, src->name);
	else if (rots->rate < 0)
		print_case_nn(rots, src->name);
}