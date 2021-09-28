#include <unistd.h>

void	ft_engstr(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str += 'A' - 'a';
		else if (*str >= 'A' && *str <= 'Z')
			*str -= 'A' - 'a';
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "\n", 1);
	ft_engstr(argv[1]);
}
