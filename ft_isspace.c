#include "libft.h"

int		ft_isspace(int c)
{
	if (((unsigned char)c >= '\t') && ((unsigned char)c <= '\r'))
		return (1);
	if ((unsigned char)c == ' ')
		return (1);
	return (0);
}
