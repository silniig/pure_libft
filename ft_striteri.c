#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	idx;

	idx = 0;
	if (!s || !f)
		return ;
	while (s[idx])
	{
		f(idx, s + idx);
		idx++;
	}
}
