#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	size_t	idx;
	size_t	len;

	idx = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	result = ft_strnew(len);
	if (result == NULL)
		return (NULL);
	while (idx < len)
	{
		result[idx] = f(s[idx]);
		idx++;
	}
	return (result);
}
