#include <stdlib.h>
#include <stdio.h>

int	is_space(char str)
{
	int	i;

	i = 0;
	if(str == ' ' || (str >= 9 && str <= 13))
		i = 1;
	return (i);
}

int	word_count(char *str)
{
	int	n;

	n = 1;
	while (*str)
	{
		if (is_space(*str) == 1)
		{
			while (*str && is_space(*str) == 1)
				str++;
			n++;
		}
		str++;
	}
printf("word count=%d\n", n);
	return (n);
}

void	ft_strcat(char *dest, char *start, char *str)
{
	while (start < str)
		*dest++ = *start++;
	*dest = 0;
}

char	**ft_split(char *str)
{
	char *start;
	char **arr;
	int	i;
	int	n;

	start = str;
	n = word_count(start);
	arr = malloc(sizeof (char *) * n);
	i = 0;
	while (*str)
	{
		if (is_space(*str) == 0)
		{
			start = str;
			while (*str != '0' && is_space(*str) == 0)
				str++;
			arr[i] = malloc(sizeof (char) * (str - start) + 1);
			ft_strcat(arr[i], start, str);
			i++;
		}
		str++;
	}
	arr[i] = 0;
	return (arr);
}

int	main(void)
{
	char **arr;
	int	i;
	
	i = 0;
arr = ft_split("  a");
//	arr = ft_split("hello hi	where    are 	you");
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}
