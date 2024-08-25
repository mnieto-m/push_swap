/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:58:10 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/08/25 21:45:19 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include "./Libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int main(int argc, int **argv);

//

// Operaciones 
void ft_swap(t_list **a);
void ss(t_list **a,t_list **b);
void pa(t_list **a, t_list **b);
void pb(t_list **a, t_list **b);
void ft_rotate(t_list **a);
void ft_rr(t_list **a,t_list **b);
void ft_re_rotate(t_list **a);
void ft_rr(t_list **a, t_list **b);
void ft_re_rotate(t_list **a);

#endif