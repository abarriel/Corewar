#include "libft.h"

unsigned int chatohi(unsigned char *str)
{
  unsigned int final;

	final = 0;
  final |= ((unsigned int)(str)[0] << 8);
	final |= ((unsigned int)(str)[1]);
  return (final);
}