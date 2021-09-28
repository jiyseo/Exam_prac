void	ft_swap(char *a, char *b)
{
	char	temp;

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

char	*ft_strrev(char *str)
{
	int	i;
	int	i;
	int	n;

	i = 0;
	j = ft_strlen(str) - 1;
	n = ft_strlen(str) / 2;
	while (n)
	{
		ft_swap(&str[i], &str[j]);
		i++;
		j--;
		n--;
	}
	return (str);
}
