#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ret;
	size_t	i;
	size_t	j;
	size_t	slen;

	i = 0;
	slen = ft_strlen(src);
	while ((i < size) && dst[i])
		i++;
	ret = i + slen;
	j = 0;
	while ((j < slen) && (i + 1 < size))
		dst[i++] = src[j++];
	if (i < size)
		dst[i] = '\0';
	return (ret);
}
