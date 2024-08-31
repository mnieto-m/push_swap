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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (ft_strlen(s) >= start + len)
		s_len = len;
	else if (start > ft_strlen(s))
		s_len = 0;
	else
		s_len = ft_strlen(s) - start;
	dst = (char *)malloc(s_len + 1);
	if (!dst || !s)
		return (0);
	while (i < s_len)
	{
		dst[i] = s[i + start];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
int	ft_isspace(int c)
{
	if (((c >= 9 && c <= 13) || c == 32))
		return (1);
	return (0);
}
void	print_data(t_data *data)
{
	int i = -1;
	while (data->nbr[++i])
		printf("[%d]\t%d\n", i, data->nbr[i]);
}
int	ft_issign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
static void	print_error(const char *str)
{
	printf("Error:\t%s", str);
	exit(EXIT_FAILURE);
}

int	ft_atoi_signal(char *str)
{
	int		i;
	int		sign;
	long	dest;

	i = 0;
	dest = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		dest = (dest * 10) + (str[i++] - '0');
	if ((sign * dest) > INT_MAX || (sign * dest) < INT_MIN)
		print_error("Overflow detected");
	return ((int)(dest * sign));
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
	int idx = 0;
	int oidx = 0;
	int ostate = 0; //OLD_STATE, former char
	int state = 0;  //STATE, new state, char at idx
	void	(*tsa[6][6])(void *, void *, int, int);
	
	//array de funciones, tsa[ostate][state]
	ft_memset(&tsa, 0, sizeof(tsa));
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
			tsa[state][EOLINE]((void *)str, data, oidx, idx + 1);

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
	int i = 1;

	ft_memset(&data, 0, sizeof(data));
	while(i >= 1 && i < argc )
	{
		automata_parse(argv[i], &data);
		i++;
	} 
	print_data(&data);
	//argv 1 solo pilla una pila 4655645
	return (0);
}
