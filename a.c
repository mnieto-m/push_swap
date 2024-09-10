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

typedef struct e_data
{
	int		i;
	int		nbr[256];
}			t_data;

void	print_data(t_data *data)
{
	int i = -1;
	while (data->nbr[++i])
		printf("[%d]\t%d\n", i, data->nbr[i]);
}

/* ----------------------------------------------------- */

/* Accion en estado, cuando llega a state == 1 */
void automata_error(int idx)
{
	printf("Parse error at idx %d\n", idx);
	exit(1);
}
/** Accion en transicion de estado, guardado de informacion */
void	automata_add_data(void *s, void *d, int oidx, int idx)
{
	char	*str;
	char	*substr;
	t_data	*data;

	str = s;
	data = d;
	substr = ft_substr(str, oidx, idx - oidx);
	//protect malloc
	data->nbr[data->i] = ft_atoi_signal(substr);
	data->i++;
	free(substr);
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

void	automata_parse(char *str, t_data *data)
{
	t_automata *var_automata;
	
	var_automata = ft_calloc(1, sizeof(t_automata));
	void	(*tsa[6][6])(void *, void *, int, int); //array de funciones, tsa[ostate][state]
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
			tsa[var_automata->ostate][var_automata->state]((void *)str, data, var_automata->oidx, var_automata->idx);
			var_automata->oidx = var_automata->idx;
		}
		if (var_automata->state == ISDIGIT && str[var_automata->idx + 1] == '\0')
			tsa[var_automata->state][EOLINE]((void *)str, data, var_automata->oidx, (var_automata->idx) + 1);
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

	t_data	data;
	int		i;

	i = 1;
	ft_memset(&data, 0, sizeof(data));
	while (i >= 1 && i < argc)
		automata_parse(argv[i++], &data);
	print_data(&data);
	return (0);
}
