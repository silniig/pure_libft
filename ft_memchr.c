#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mem;
	size_t			i;

	mem = (unsigned char *)s;
	i = 0;
	while (i++ < n)
		if (mem[i - 1] == (unsigned char)c)
			return (void *)(mem + i - 1);
	return (NULL);
}
