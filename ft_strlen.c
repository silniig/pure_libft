#include "libft.h"

size_t		ft_strlen(const char *str)
{
	size_t result;

	result = 0;
	while (*(str++))
		result++;
	return (result);
}
