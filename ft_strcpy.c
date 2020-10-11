#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i++])
		dst[i - 1] = src[i - 1];
	dst[i - 1] = '\0';
	return (dst);
}
