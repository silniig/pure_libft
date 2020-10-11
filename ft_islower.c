#include "libft.h"

int		ft_islower(int c)
{
	if (c < 0 || c > 255)
		return (0);
	if (((unsigned char)c >= 'a') && ((unsigned char)c <= 'z'))
		return (1);
	return (0);
}
