#include <stdlib.h>
#include <stdio.h>

unsigned int	get_sign(int nbr)
{
	unsigned int	n;

	if (nbr < 0)
		n = -nbr;
	else n = nbr;
	return (n);
}

int	get_divisor(int nbr, int *cnt)
{
	unsigned int	n;
	int	divisor;

	*cnt = 1;
	n = get_sign(nbr);
	divisor = 1;
	while (n >= 10)
	{
		divisor *= 10;
		n /= 10;
		(*cnt)++;
	}
	return (divisor);
}

char	*ft_itoa(int nbr)
{
	char *num;
	unsigned int n;
	int	divisor;
	int	cnt;
	int share;
	int	i;

	i = 0;
	divisor = get_divisor(nbr, &cnt);
	num = malloc(sizeof (char) * (cnt + 2));
	if (nbr < 0)
	{
		num[i] = '-';
		i++;
	}
	n = get_sign(nbr);
	while (divisor > 0)
	{
		share = n / divisor;
		num[i] = share + '0';
		n %= divisor;
		divisor /= 10;
		i++;
	}
	return (num);
}

int	main(void)
{
	printf("%s", ft_itoa(23923455));
}
