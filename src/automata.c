/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:46:11 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/07/30 14:43:56 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

static void	automata_add_data(void *s, t_list **a, int oidx)
{
	char	*str;
	int		*numb;
	int		flag;

	flag = 0;
	str = s;
	numb = malloc(sizeof(int));
	if (!numb)
		return (free(numb), automata_error(a));
	*numb = ft_atoi_signal(str + oidx, &flag);
	if (flag == -1)
		return (free(numb), automata_error(a));
	ft_lstadd_back((a), ft_lstnew((void *)numb));
	if (!a)
		return (free(numb), automata_error(a));
	if (ft_lstisduplicate(a) == 0)
		return (automata_error(a));
}

static int	automata_getstate(int ostate, int dict_idx)
{
	const int	matrix[5][4] = {
	{2, 3, 4, 1},
	{1, 1, 1, 1},
	{2, 3, 4, 1},
	{1, 1, 4, 1},
	{2, 1, 4, 1}};

	return (matrix[ostate][dict_idx]);
}

static int	automata_change_state(int ostate, char c)
{
	if (ft_isspace(c) != 0)
		return (automata_getstate(ostate, 0));
	else if (ft_issign(c) != 0)
		return (automata_getstate(ostate, 1));
	else if (ft_isdigit(c) != 0)
		return (automata_getstate(ostate, 2));
	else
		return (automata_getstate(ostate, 3));
}

static void	end_line(char *str, t_list **a, t_automata dt_aut)
{
	if (dt_aut.state == ISSIGN && str[dt_aut.idx + 1] == '\0')
		automata_error(a);
	if (dt_aut.state == ISDIGIT && str[dt_aut.idx + 1] == '\0')
		(dt_aut.tsa[dt_aut.state][EOLINE]((void *)str, (a), dt_aut.oidx));
}

void	automata_parse(char *str, t_list **a)
{
	t_automata	dt_aut;

	ft_memset((void *)&dt_aut, 0, sizeof(dt_aut));
	dt_aut.tsa[ISDIGIT][ISSPACE] = automata_add_data;
	dt_aut.tsa[ISDIGIT][EOLINE] = automata_add_data;
	dt_aut.idx = -1;
	while (str[++(dt_aut.idx)])
	{
		(dt_aut.state = automata_change_state(dt_aut.ostate, str[dt_aut.idx]));
		if (dt_aut.state == 1)
			automata_error(a);
		if (dt_aut.tsa[dt_aut.ostate][dt_aut.state] != NULL)
		{
			(dt_aut.tsa[dt_aut.ostate][dt_aut.state]((void *)str, a,
						dt_aut.oidx));
			dt_aut.oidx = dt_aut.idx;
		}
		if (str[dt_aut.idx + 1] == '\0')
			end_line(str, a, dt_aut);
		dt_aut.ostate = dt_aut.state;
	}
}
