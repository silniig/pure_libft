#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*f;
	unsigned char	*s;
	size_t			i;

	i = 0;
	f = (unsigned char *)s1;
	s = (unsigned char *)s2;
	while ((i < n) && (f[i] - s[i] == 0))
		i++;
	return ((i < n) ? (f[i] - s[i]) : 0);
}
