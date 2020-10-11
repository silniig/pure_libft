#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (result == NULL)
		return (result);
	return (ft_memset(result, 0, size));
}
