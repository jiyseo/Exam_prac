#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	i;
	int	*num;
	int	bound;

	if (start > end)
	{
		i = start;
		start = end;
		end = i;
	}
	bound = end - start + 1;
	num = malloc(sizeof(int) * bound);
	i = 0;
	while (i < bound)
	{
		num[i] = start + i;
		i++;
	}
	return (num);
}

int	main(void)
{
	int	*num;
	
	num = ft_range(1, 3);
	printf("%d", num[0]);
	printf("%d", num[1]);
	printf("%d", num[2]);

}
