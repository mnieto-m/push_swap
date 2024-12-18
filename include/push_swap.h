/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:58:10 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/12/18 17:13:04 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../Libft/include/libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct s_automata
{
	int		idx;
	int		oidx;
	int		ostate;
	int		state;
	void	(*tsa[6][6])(void *, t_list **, int);
}			t_automata;

typedef enum e_states
{
	INIT,
	ERR,
	ISSPACE,
	ISSIGN,
	ISDIGIT,
	EOLINE
}			t_states;


int main(int argc, char **argv);

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


// automata
void	automata_parse(char *str, t_list **a);
void	automata_error(t_list **a);
#endif