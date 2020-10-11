#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*result;

	if (size + 1 == 0)
		return (NULL);
	result = (char *)malloc(size + 1);
	if (result == NULL)
		return (NULL);
	ft_memset(result, '\0', size + 1);
	return (result);
}
