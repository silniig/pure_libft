#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*mem;

	mem = (unsigned char *)b;
	while (len > 0)
		mem[--len] = (unsigned char)c;
	return (b);
}
