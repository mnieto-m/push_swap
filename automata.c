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

typedef struct s_feed_automata
{

	char	*str;
	char	*substr;
	int 	*num;
	t_list	*new;
}			t_feed_automata;

void printList(t_list **lst) {
    while (*lst != NULL) {
        printf("%i\n", *((int *)(*lst)->content));
        *lst = (*lst)->next;
    }
}
/* ----------------------------------------------------- */

/* Accion en estado, cuando llega a state == 1 */
void automata_error(int idx)
{
	printf("Parse error at idx %d\n", idx);
	exit(1);
}
/** Accion en transicion de estado, guardado de informacion */
void	automata_add_data(void *s, t_list **a, int oidx, int idx)
{
	t_feed_automata feed;

	feed.str = s;
	feed.substr = ft_substr(feed.str, oidx, idx - oidx);
	feed.num = malloc(sizeof (feed.num));
	*feed.num = ft_atoi_signal(feed.substr);
	feed.new = ft_lstnew((void *)feed.num);
	ft_lstadd_back((a), feed.new);
	free(feed.num);
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

void	automata_parse(char *str, t_list **a)
{
	t_automata *var_automata;
	
	var_automata = ft_calloc(1, sizeof(t_automata));
	void	(*tsa[6][6])(void *, t_list **, int, int); //array de funciones, tsa[ostate][state]
	ft_memset(tsa, 0, sizeof(tsa));	
	tsa[ISDIGIT][ISSPACE] = automata_add_data;
	tsa[ISDIGIT][EOLINE] = automata_add_data;
	var_automata->idx = -1;
	while (str[++(var_automata->idx)])
	{
		//obtener estado actual de str[idx]
		var_automata->state = automata_change_state(var_automata->ostate, str[var_automata->idx]);
		if (var_automata->state == 1) //estado sencillo, llamamos a error
			automata_error(var_automata->idx);
		//str //desde oidx hasta idx, itoa de substr,
		// else if ((state == 2 && ostate == 4) ||
		// 		(state == 4 && str[idx + 1]) == '\0')
		if (tsa[var_automata->ostate][var_automata->state] != NULL)
		{
			tsa[var_automata->ostate][var_automata->state]((void *)str, a, var_automata->oidx, var_automata->idx);
			var_automata->oidx = var_automata->idx;
		}
		if (var_automata->state == ISDIGIT && str[var_automata->idx + 1] == '\0')
			tsa[var_automata->state][EOLINE]((void *)str, &(*a), var_automata->oidx, (var_automata->idx) + 1);
		var_automata->ostate = var_automata->state; //antes de continuar la iteracion
	}
	free(var_automata);
}
/* ----------------------------------------------------- */

/**
 * ./a.out "234 +568 -321 3a34 " -> error
 */

int	main(int argc, char **argv)
{
	t_list *a;
/* 	t_list b; 
 */	int		i;

	i = 1;
	a = 0;
	while (i >= 1 && i < argc)
	{
		automata_parse(argv[i++], &a);
	}
	printList((&a));
	ft_lstclear(&a,free);
	return (0);
}
