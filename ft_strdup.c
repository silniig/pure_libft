#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*result;

	i = 0;
	while (src[i])
		i++;
	result = (char *)malloc(i + 1);
	if (result == NULL)
		return (NULL);
	while (i >= 0)
	{
		result[i] = src[i];
		i--;
	}
	return (result);
}
