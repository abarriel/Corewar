#include "libft.h"

int btoi(int n)
{
 	int decimal;
 	int i; 
 	int rem;

 	decimal = 0;
 	i = 0;
 	rem = 0;
    while (n != 0)
    {
        rem = n % 10;
        n /= 10;
        decimal += rem * ft_pow_base(2, i);
        ++i;
    }
    return (decimal);
}