#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "./Libft/libft.h"
#include <ctype.h>

typedef struct e_automata
{
	int idx ;
	int oidx ;
	int ostate;//OLD_STATE, former char
	int state ; 

} t_automata;
typedef enum e_states
{
	INIT,
	ERR,
	ISSPACE,
	ISSIGN,
	ISDIGIT,
	EOLINE
}	t_states;

typedef struct e_data
{
	int i;
	int nbr[256];
}	t_data;

void	print_data(t_data *data)
{
	int i = -1;
	while (data->nbr[++i])
		printf("[%d]\t%d\n", i, data->nbr[i]);
}
int ft_is_sign(char c)
{
	if(c == '+' || c == '-')
		return(1);
	return(0);
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
	char *str;
	char *substr;
	t_data *data;

	str = s;
	data = d;
	substr = ft_substr(s, oidx, idx - oidx);
	//protect malloc
	data->nbr[data->i] = ft_atoi(substr);
	data->i++;
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
	int idx = 0;
	int oidx = 0;
	int ostate = 0; //OLD_STATE, former char
	int state = 0;  //STATE, new state, char at idx
	void	(*tsa[6][6])(void *, void *, int, int);
	
	//array de funciones, tsa[ostate][state]
	memset(&tsa, 0, sizeof(tsa));
	tsa[ISDIGIT][ISSPACE] = automata_add_data;
	tsa[ISDIGIT][EOLINE] = automata_add_data;

	idx = -1;
	while (str[++idx])
	{
		//obtener estado actual de str[idx]
		state = automata_change_state(ostate, str[idx]);

		if (state == 1) //estado sencillo, llamamos a error
			automata_error(idx);

		//str //desde oidx hasta idx, itoa de substr, creas nuevo nodo con ese num
		// else if ((state == 2 && ostate == 4) || 
		// 		(state == 4 && str[idx + 1]) == '\0')
		if (tsa[ostate][state] !=  NULL)
		{
			tsa[ostate][state]((void *)str, data, oidx, idx);
			oidx = idx;
		}
		if (state == ISDIGIT && str[idx + 1] == '\0')
			tsa[state][EOLINE]((void *)str, data, idx, idx + 1);

		ostate = state; //antes de continuar la iteracion
	}
}
/* ----------------------------------------------------- */

/**
 * ./a.out "234 +568 -321 3a34 " -> error
 */

int	main(int argc, char **argv)
{
	t_data data;

	memset(&data, 0, sizeof(data));
	automata_parse(argv[1], &data);
	print_data(&data);
	return (0);
}
