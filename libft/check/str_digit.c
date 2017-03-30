#include "libft.h"

int	ft_sdigit(char *c)
{
	if (*c == '-' || *c == '+')
		c++;
	if (*c == '\0')
		return (1);
	while (*c)
	{
		if (*c != '\0' && (*c < '0' || *c > '9'))
			return (1);
		c++;
	}
	return (0);
}
