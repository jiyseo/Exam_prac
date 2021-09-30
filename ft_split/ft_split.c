#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;
	int	cnt;
	
	i = 0;
	cnt = 1;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			cnt++;
		i++;
	}
	return (cnt);
}

void	ft_strcpy(char *dest, char *start, char *end)
{
	while (start < end)
		*(dest++) = *(start++);
	*dest = 0;
}
char	**ft_split(char *str)
{
	char	**arr;
	int	n;
	int	i;
	char	*start;
	
	i = 0;
	n = ft_strlen(str);
	arr = malloc(sizeof(char*) * n);
	if (!arr)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == ' ' || (*str >= 9 && *str <= 13))
			;
		else
		{
			start = str;
			while (*str != '\0' && (*str != ' ' && (*str < 9 || *str > 13)))
				str++;
			arr[i] = malloc(sizeof(char) * (str - start) + 1);
			ft_strcpy(arr[i], start, str);
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
	arr = ft_split("hello hi	where    are 	you");
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}
