#include <unistd.h>
#include <stdlib.h>

int	is_space(char ch)
{
	if (ch == ' ' || (ch >= 9 && ch <= 13))
		return (1);
	return (0);
}

int	ft_word_cnt(char *str)
{
	int	cnt;

	cnt = 1;
	while (*str)
	{
		if (is_space(*str) == 1)
		{
			while (*str && is_space(*str) == 1)
				str++;
			cnt++;
		}
		str++;
	}
	return (cnt);
}

void	ft_strcpy(char *dst, char *start, char *str)
{
	while (start < str)
		*dst++ = *start++;
	*dst = '\0';
}

void	ft_strprt(char *str)
{
	int	i;

	i = 0;
	while(str[i] == '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
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
	i = 0;
	while (*str)
	{
		if (*str && !is_space(*str))
		{
			start = str;
			while (*str && !is_space(*str))
				str++;
			arr[i] = malloc(sizeof (char) * (str - start) + 1);
			ft_strcpy(arr[i], start, str);
			i++;
		}
		str++;
	}
	arr[i] = 0;
	while (--i >= 0)
	{
		ft_strprt(arr[i]);
		write(1, " ", 1);
		
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
