#include "libft.h"

unsigned int chatohi(unsigned char *str)
{
  unsigned int final;

	final = 0;
  //ft_printf("------------------------------------<<<<<><><><%02x %02x\n", str[0], str[1]);
  final |= ((unsigned int)(str)[0] << 8);
	final |= ((unsigned int)(str)[1]);
  return (final);
}
