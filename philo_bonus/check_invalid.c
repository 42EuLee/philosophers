#include "philosopher_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_isint(char *str)
{
	int		i;
	long	n;

	i = 0;
	n = (long)ft_atoi(str);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (n > INT_MAX || n < INT_MIN)
			return (0);
		if (ft_isdigit(str[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_invalid(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (1);
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) < 1)
		return (1);
	i = 1;
	while (i < 5)
	{
		if ((i > 1) && (ft_atoi(argv[i]) < 60))
			return (1);
		if (ft_isint(argv[i]) == 0)
			return (1);
		i++;
	}
	if (argv[5] == NULL)
		return (0);
	if (ft_isint(argv[5]) == 0)
		return (1);
	return (0);
}
