#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	if (!n || (!dst && !src))
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n-- > 0)
		d[n] = s[n];
	return (dst);
}
