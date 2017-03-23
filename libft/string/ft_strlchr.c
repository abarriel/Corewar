#include "libft.h"

size_t		ft_strlchr(char *s, int c)
{
	size_t	n;
	char	c1;
	size_t	len;

	len = 0;
	n = ft_strlen(s) + 1;
	c1 = (unsigned char)c;
	while (n != '\0')
	{
		if (*s != c1)
		{
			s++;
			len++;
		}
		else
			return (len);
		n--;
	}
	return (0);
}

