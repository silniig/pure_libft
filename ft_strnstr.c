#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return (char *)(haystack);
	while ((i < len) && haystack[i])
	{
		while ((i + j < len) && needle[j] && (needle[j] == haystack[i + j]))
			j++;
		if (!needle[j])
			return (char *)(haystack + i);
		else
			j = 0;
		i++;
	}
	return (NULL);
}
