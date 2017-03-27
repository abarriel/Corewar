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

int btoi(int n)
{
 int decimal=0, i=0, rem;
    while (n!=0)
    {
        rem = n%10;
        n/=10;
        decimal += rem*ft_pow_base(2,i);
        ++i;
    }
    return decimal;
}