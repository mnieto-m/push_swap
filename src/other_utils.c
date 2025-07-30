/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:45:14 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/07/30 14:50:49 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	ft_maxint(int a, int b)
{
	if (b > a)
		return (b);
	return (a);
}

int	ft_minint(int a, int b)
{
	if (b < a)
		return (b);
	return (a);
}

int	ft_mod(int a, int b)
{
	return (((a % b) + b) % b);
}

int	ft_orded(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
		{
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
