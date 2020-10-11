#include "libft.h"

void	ft_memswap(void *src, void *dst, size_t size)
{
	size_t          i;
	unsigned char   b;

	i = 0;
	while (i < size)
	{
		b = *((unsigned char *)src);
		*((unsigned char *)src) = *((unsigned char *)dst);
		*((unsigned char *)dst) = b;
		++i;
		++src;
		++dst;
	}
}
