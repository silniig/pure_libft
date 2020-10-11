#include "libft.h"

int		ft_isdigit(int c)
{
	if (c < 0 || c > 255)
		return (0);
	if (((unsigned char)c >= '0') && ((unsigned char)c <= '9'))
		return (1);
	return (0);
}
