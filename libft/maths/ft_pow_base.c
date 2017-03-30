#include "libft.h"

int ft_pow_base(int x, unsigned int y)
{
	int temp;

	if (y == 0)
		return (1);
	temp = ft_pow_base(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp);
	else
		return (x * temp * temp);
}