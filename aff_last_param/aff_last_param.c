#include <unistd.h>

void	ft_strprt(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

int	main(int argc, char **argv)
{
	ft_strprt(argv[argc - 1]);
	write(1, "\n", 1);
}
