#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
int	ft_issign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}
int	ft_isspace(int c)
{
	if (((c >= 9 && c <= 13) || c == 32))
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
int	ft_atoi(const char *str)
{
	int	dest;
	int	sign;

	dest = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		dest = (dest * 10) + *str - 48;
		str++;
	}
	return (dest * sign);
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

int main(void)
{
	char *str;
	int i;
	int a;

	str = "- 4655645";
	a = ft_atoi(str);	
	printf("%i\n", a);
	i =ft_atoi_signal(str);
	printf("%i\n", i);
}