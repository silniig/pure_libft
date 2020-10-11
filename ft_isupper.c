#include "libft.h"

int		ft_isupper(int c)
{
	if (c < 0 || c > 255)
		return (0);
	if (((unsigned char)c >= 'A') && ((unsigned char)c <= 'Z'))
		return (1);
	return (0);
}
