/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:39:14 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/05/28 17:19:46 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	automata_error(t_list **a)
{
	ft_putstr_fd("error\n",2);
	ft_lstclear(a, free);
	exit(EXIT_FAILURE);
}
void success_order(t_list **a)
{	
	ft_lstclear(a, free);
	exit(EXIT_SUCCESS);
}
void fail_malloc(t_list **a)
{
	ft_lstclear(a, free);
	exit(EXIT_FAILURE);
	
}