#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return (char *)(haystack);
	while (haystack[i])
	{
		while (needle[j] && (needle[j] == haystack[i + j]))
			j++;
		if (!needle[j])
			return (char *)(haystack + i);
		else
			j = 0;
		i++;
	}
	return (NULL);
}
