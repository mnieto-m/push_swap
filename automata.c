#include "./Libft/libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct s_automata
{
	int		idx;
	int		oidx;
	int 	ostate; //OLD_STATE
	int		state;

}			t_automata;
//implemetar estructuras escritas pero
typedef enum e_states
{
	INIT,
	ERR,
	ISSPACE,
	ISSIGN,
	ISDIGIT,
	EOLINE
}			t_states;

void printList(t_list *a)
{
	t_list *lst;
	lst = a;
	while (lst != NULL) {
		int nb = *(int *)lst->content;
		printf("%i\n", nb);
	lst = (lst)->next;
	}
}
/* ----------------------------------------------------- */

/* Accion en estado, cuando llega a state == 1 */
void automata_error( t_list **a)
{
	printf("Parse error\n");
	ft_lstclear(a, free);
	exit(EXIT_FAILURE);
}

void	automata_add_data(void *s, t_list **a, int oidx)
{
	char	*str;
	int 	*numb;
	int 	flag;

	flag = 0;
	str = s;
	numb = malloc(sizeof(int));
	*numb =  ft_atoi_signal(str + oidx, &flag);
	if (flag == -1)
		return (free(numb),automata_error(a));
	ft_lstadd_back((a), ft_lstnew((void *) numb));	
}


int	automata_getstate(int ostate, int dict_idx)
{
	int matrix[5][4] = {
		//s +-  D  ^
		{2, 3, 4, 1}, // 0 INIT
		{1, 1, 1, 1}, //1 ERR
		{2, 3, 4, 1}, //2 ISSPACE
		{1, 1, 4, 1}, //3 ISSIGN
		{2, 1, 4, 1}  //4 ISDIGIT
	};
	return (matrix[ostate][dict_idx]);
}

// Determinar a qué diccionario pertenece el caracter
// Devolver el estado de getstate
int	automata_change_state(int ostate, char c)
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
// quitar puntero a var automata
void	automata_parse(char *str, t_list **a)
{
	t_automata var_automata;
	
	ft_memset((void *)&var_automata, 0, sizeof(var_automata));
	void	(*tsa[6][6])(void *, t_list **, int); //array de funciones, tsa[ostate][state]
	ft_memset(tsa, 0, sizeof(tsa));	
	tsa[ISDIGIT][ISSPACE] = automata_add_data;
	tsa[ISDIGIT][EOLINE] = automata_add_data;
	var_automata.idx = -1;
	while (str[++(var_automata.idx)])
	{
		//obtener estado actual de str[idx]
		var_automata.state = automata_change_state(var_automata.ostate, str[var_automata.idx]);
		if (var_automata.state == 1) //estado sencillo, llamamos a error
			automata_error(a);
		//str //desde oidx hasta idx, itoa de substr,
		if (tsa[var_automata.ostate][var_automata.state] != NULL)
		{
			tsa[var_automata.ostate][var_automata.state]((void *)str, a, var_automata.oidx);
			var_automata.oidx = var_automata.idx;
		}
		if (var_automata.state == ISDIGIT && str[var_automata.idx + 1] == '\0')
			tsa[var_automata.state][EOLINE]((void *)str, (a), var_automata.oidx);
		var_automata.ostate = var_automata.state; //antes de continuar la iteracion
	}
}
/* ----------------------------------------------------- */

/**
 * ./a.out "234 +568 -321 3a34 " . error
 */


int	main(int argc, char **argv)
{
	t_list *a;
	int		i;

	i = 1;
	a = NULL;
	while (i >= 1 && i < argc)
		automata_parse(argv[i++], &a);
	printList(a);
	ft_lstclear(&a, free);
	return (0);
}
