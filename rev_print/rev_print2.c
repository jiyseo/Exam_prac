#include <unistd.h>

void	ft_swap(char *a, char *b)
{
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*rev_print(char	*str)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str);
	while (i < j)
	{
		ft_swap(&str[i], &str[j]);
		i++;
		j--;
	}
	j = 0;
	while (j <= ft_strlen(str))
	{
		write(1, &str[j++], 1);
	}
	return (str);
}

int	main(void)
{
	char	str[256];
	str	= {"hello"};

	rev_print(str);
}
