#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s)
		return (NULL);
	if (len + 1 == 0)
		return (NULL);
	result = ft_strnew(len);
	if (result == NULL)
		return (NULL);
	return ((char *)ft_memcpy(result, s + start, len));
}
