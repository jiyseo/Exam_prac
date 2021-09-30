#include <unistd.h>

int	ft_atoi(char *str)
{
	int	n;

	n = 0;
	while (*str)
	{
		n = n * 10 + *str - '0';
		str++;
	}
	return (n);
}

void	putnbr(int	n)
{
	if (n > 9)
		putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

void	ft_prime(int n)
{
	int	i;
	if (n == 1)
		putnbr(1);		
	else
	{
		i = 1;
		while (n > 1)
		{
			if (n % ++i == 0)
			{	
				putnbr(i);
				n /= i;
				if (n > 1)
					write(1, "*", 1);
				--i;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2 && *argv[1])
		ft_prime(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
