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
	void	(*tsa[6][6])(void *, t_list **, int);
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
	printf("Error\n");
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
	if(!numb)
		return(free(numb),automata_error(a));
	*numb =  ft_atoi_signal(str + oidx, &flag);
	if (flag == -1)
		return (free(numb),automata_error(a));
	ft_lstadd_back((a), ft_lstnew((void *) numb));	
	if(!a)
		return(free(numb), automata_error(a));
	if(ft_lstisduplicate(a) == 0)
		return(automata_error(a));
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
static void end_line(char *str, t_list **a, t_automata var_automata)
{
		if (var_automata.state == ISSIGN  && str[var_automata.idx + 1] == '\0')
			automata_error(a);
		if(var_automata.state == ISDIGIT  && str[var_automata.idx + 1] == '\0') 
			var_automata.tsa[var_automata.state][EOLINE]((void *)str, (a), var_automata.oidx);	
}


void	automata_parse(char *str, t_list **a)
{
	t_automata var_automata;
	
	ft_memset((void *)&var_automata, 0, sizeof(var_automata));
	var_automata.tsa[ISDIGIT][ISSPACE] = automata_add_data;//proteger malloc???
	var_automata.tsa[ISDIGIT][EOLINE] = automata_add_data;//proteger malloc???
	var_automata.idx = -1;
	while (str[++(var_automata.idx)])
	{
		//obtener estado actual de str[idx]
		var_automata.state = automata_change_state(var_automata.ostate, str[var_automata.idx]);
		if (var_automata.state == 1) //estado sencillo, llamamos a error
			automata_error(a);
		//str //desde oidx hasta idx, itoa de substr,
		if (var_automata.tsa[var_automata.ostate][var_automata.state] != NULL)
		{
			var_automata.tsa[var_automata.ostate][var_automata.state]((void *)str, a, var_automata.oidx);
			var_automata.oidx = var_automata.idx;
		}
		if (str[var_automata.idx + 1] == '\0')
 			end_line(str, a, var_automata);//antes de continuar la iteracion
		var_automata.ostate = var_automata.state;
	}
}
/* ----------------------------------------------------- */

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
