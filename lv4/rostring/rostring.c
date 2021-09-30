#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	is_space(char ch)
{
	if (ch == ' ' || (ch >= 9 && ch <= 13))
		return (1);
	return (0);
}

int	word_count(char *str)
{
	int	i;
	int	cnt;

	cnt = 0;
	while (str[i] != '\0')
	{
		if (is_space(str[i]))
		{
			while (str[i] && is_space(str[i]))
				i++;
			cnt++;
		}
		else
			i++;
	}
	return (cnt);
}

void	ft_strcpy(char * dest, char *start, char *str)
{
	while (start < str)
		*dest++ = *start++;
	*dest = '\0';
}

void    ft_strprt(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		//  printf("i = %d, str[i] = %c\n", i, str[i]);
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_split(char *str)
{
	char	**arr;
	char	*start;
	int	i;
	int	cnt;

	cnt = word_count(str);
	arr = malloc(sizeof(char *) * (cnt + 1));
	i = 0;
	while (*str != '\0')
	{
		if (!is_space(*str))
		{
			start = str;
			while (*str && !is_space(*str))
				str++;
			arr[i] = malloc(sizeof(char) * ((str - start) + 1));
			ft_strcpy(arr[i], start, str);
			//printf("i = %d, arr[i] = %s\n", i, arr[i]);
			i++;
		}
		else
			str++;
	}
	arr[i] = 0;
	i = 1;
	while(arr[i] != 0)
	{
		ft_strprt(arr[i]);
		write(1, " ", 1);
		i++;
	}
	ft_strprt(arr[0]);
}

int	main(int ac, char **av)
{
	if(ac == 2)
	{
		ft_split(av[1]);
	}
	write(1, "\n", 1);
}
