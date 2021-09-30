#include <unistd.h>
#include <stdlib.h>

int	is_space(char str)
{
	if (str == ' ' || (str >= 9 && str <= 13))
		return (0);
	return (1);
}

int	ft_word_cnt(char *str)
{
	int	cnt;

	cnt = 1;
	while (*str)
	{
		if (is_space(*str) == 0)
			cnt++;
		str++;
	}
	return (cnt);
}

void	ft_strcat(char *dst, char *start, char *str)
{
	while (start < str)
		*dst++ = *start++;
	*dst = 0;
}

void	ft_split(char *str)
{
	char *start;
	char **arr;
	int	i;
	int	n;

	start = str;
	n = ft_word_cnt(start);
	arr = malloc(sizeof (char*) * n);
	if (!arr)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str && is_space(*str) == 1)
		{
			start = str;
			while (is_space(*str) == 1)
				str++;
			arr[i] = malloc(sizeof (char) * (str - start) + 1);
			ft_strcat(arr[i], start, str);
			i++;
		}
		str++;
	}
	arr[i] = 0;
	i--;
	while (i >= 0)
	{
		ft_strprt(arr[i]);
		i--;
	}
}

void	ft_strprt(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_split(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
