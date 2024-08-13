int	automata_getstate(int ostate, int dict_idx)
{
	int matrix[5][4] = {
		//s +-  A  ^
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
	else if (ft_isnum(c) != 0)
		return (automata_getstate(ostate, 2));
	else
		return (automata_getstate(ostate, 3));
}

void	automata_parse(char *str)
{
	int idx;
	int oidx;
	int ostate; //OLD_STATE, former char
	int state;  //STATE, new state, char at idx

	idx = -1;
	while (str[++idx])
	{
		state = automata_change_state(ostate, str[idx]);
		if (state == 1) //estado sencillo, llamaamos a error
			//return pw_error()
		else if (ostate == 4 && state == 2)//[DIGIT][SPACE]
			//guardamos numero -> substr desde oidx hasta idx, itoa de substr, creas nuevo nodo con ese num
		else if (state == 2)
			//actualizas oidx
		ostate = state; //antes de continuar la iteracion
	}
}