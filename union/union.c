#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_union_str(char *arr, char *str)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (arr[(int)str[i]] == '0')
		{
			arr[(int)str[i]] = '1';
			write(1, &str[i], 1);
		}
		i++;
	}
}

void	ft_union(char *str1, char *str2)
{
	int	i;
	char	arr[256];

	i = 0;
	while (i < 255)
	{
		arr[i] = '0';
		i++;
	}
	ft_union_str(arr, str1);
	ft_union_str(arr, str2);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_union(argv[1], argv[2]);
	}
	write(1, "\n", 1);
}

