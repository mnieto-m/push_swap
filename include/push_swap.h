/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:58:10 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/07/30 14:59:25 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/include/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

typedef struct s_automata
{
	int					idx;
	int					oidx;
	int					ostate;
	int					state;
	void				(*tsa[6][6])(void *, t_list **, int);
}						t_automata;

typedef enum e_states
{
	INIT,
	ERR,
	ISSPACE,
	ISSIGN,
	ISDIGIT,
	EOLINE
}						t_states;

typedef struct s_node
{
	int					value;
	struct s_node		*prev;
	struct s_node		*next;
}						t_node;

typedef struct s_loc_node
{
	struct s_node		*node;
	int					loc;
}						t_loc_node;

typedef struct s_rated_node
{
	struct s_loc_node	src_nd;
	struct s_loc_node	dst_nd;
	int					rate;
}						t_rated_node;

typedef struct s_stack
{
	struct s_node		*head;
	struct s_loc_node	peak;
	int					size;
	char				name;
}						t_stack;

typedef struct s_stacks
{
	int					median;
	int					size;
	struct s_stack		a;
	struct s_stack		b;
	struct s_node		nodes[];
}						t_stacks;

typedef struct s_ord
{
	bool				(*gt)(int a, int b);
	t_loc_node			top;
}						t_ord;

int						main(int argc, char **argv);

//

// Operaciones
bool					greater(int a, int b);
bool					lower(int a, int b);
void					set_top(t_stack *stack, t_ord *ord);

t_stacks				*init_stack(t_list *a, int size);
void					head_to_bottom(t_stack *stack, t_ord *ord);
bool					stack_sorted(t_stack *stack, t_ord *ord, bool relative);

void					rot(t_stack *stack, bool print);
void					rrot(t_stacks *stacks, bool print);
void					rrev(t_stacks *stacks, bool print);
void					rev(t_stack *stack, bool print);
void					push(t_stack *src, t_stack *dst, bool print);
void					swap(t_stack *stack, bool print);
void					sswap(t_stacks *stacks, bool print);

void					print_rots(t_rated_node *rots, t_stack *src);
void					calc_rots(t_rated_node *rnd);

void					push_stack(t_stack *src, t_stack *dst, t_ord *ord,
							int limit);

void					sort_2(t_stack *stack);
void					sort_3(t_stack *stack, t_ord *ord, bool relative);
void					turk(t_stacks *s, int median, int size);

int						*parse(int argc, const char *argv[], int *size,
							int *median);

int						ft_mod(int a, int b);
int						ft_minint(int a, int b);
int						ft_maxint(int a, int b);

void					get_tg(t_stack *src, t_stack *dst, t_rated_node *rnd,
							t_ord *ord);
void					get_rots(t_stack *src, t_stack *dst, t_ord *ord,
							t_rated_node *rnd);
void					get_cost(t_stack *src, t_stack *dst, t_rated_node *rnd);
bool					out_of_bounds(int value, t_ord *ord);
int						get_median(t_list *a, int size);

// automata
void					automata_parse(char *str, t_list **a);
void					automata_error(t_list **a);
int						ft_orded(t_list *a);
void					success_order(t_list *a);
t_list					*ft_lstcopy_new(t_list *lst);

#endif