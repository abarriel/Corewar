#include "libft.h"

int cmp_4_oct(unsigned char *one, unsigned char *two)
{
  if (one[0] == two[0] && one[1] == two[1] &&
    one[2] == two[2] && one[3] == two[3])
    return (1);
  return(0);
}