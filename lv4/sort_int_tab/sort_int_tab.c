void	ft_swap(int	*a, int *b)
{
	int	c;
	
	c = *a;
	*a = *b;
	*b = c;
}

void	sort_int_tab(int *tab, unsigned int size)
{
	int	i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size - 1)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
