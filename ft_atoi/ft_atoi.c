#include<stdio.h>

int	ft_atoi(const char *str)
{
	int	n;
	int	sign;

	sign = 1;
	n = 0;
	while (*str == ' ' || (*str >= 9 && *str<= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			n = n * 10 + *str -'0';
		else
			break ;
		str++;
	}
	return (n * sign);
}

int	main(void)
{
	printf("%d\n", ft_atoi("  +--2345"));
	printf("%d\n", ft_atoi("---453")); 
}
