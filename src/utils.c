#include "../philo.h"

void	put_char(char c, int fd)
{
	write (fd, &c, 1);
}

void	put_string(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		put_char(s[i], fd);
		i++;
	}
}

int	digit_check(char *c)
{
	while (c && *c)
	{
		if (*c < '0' || *c > '9')
			return (0);
		c++;
	}
	return (1);
}

int	is_int(char *str)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		if (result > 2147483647)
			return (-1);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (1);
}

int ft_atoi(char *str)
{
    int i = 0;
    int nb = 0;
    int mu = 1;
    while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            mu = mu * -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return(nb * mu);
}
