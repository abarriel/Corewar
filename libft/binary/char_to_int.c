#include "libft.h"

unsigned int chatoi(unsigned char *str)
{
  unsigned int final;

	final = 0;
	final |= ((unsigned int)(str)[0] << 24);
	final |= ((unsigned int)(str)[1] << 16);
	final |= ((unsigned int)(str)[2] << 8);
	final |= ((unsigned int)(str)[3]);
	return (final);
}