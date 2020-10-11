#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!len || (!dst && !src))
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (d <= s)
		while (i++ < len)
			d[i - 1] = s[i - 1];
	else
		while (i < len--)
			d[len] = s[len];
	return (dst);
}
