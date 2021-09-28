#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*rev_print(char *str)
{
	 int	i;
	 int	n;
	char	rev_str[256];
	
	i = 0;
	n = ft_strlen(str) - 1;
	while (n >= 0)
	{
		rev_str[n] = str[i];
		n--;
		i++;
	}
	i = 0;
	n = ft_strlen(str);
	while(i < n)
		write(1, &rev_str[i++], 1);
	return (&rev_str[0]);
}

int	main(void)
{
	rev_print("rainbow dash");
	write(1, "\n", 1);
	rev_print("Ponies are awesome");
	write(1, "\n", 1);
	rev_print("");
	write(1, "\n", 1);
	return (0);
}
