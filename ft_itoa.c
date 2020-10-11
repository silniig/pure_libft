#include "libft.h"

static size_t	ft_count_digits(int n)
{
	size_t	r;

	r = (n > 0) ? 0 : 1;
	while (n != 0)
	{
		n /= 10;
		r++;
	}
	return (r);
}

char			*ft_itoa(int n)
{
	size_t	count;
	char	*res;
	size_t	i;

	count = ft_count_digits(n);
	res = ft_strnew(count);
	if (res == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
		res[i++] = '-';
	while (count > i)
	{
		if (n < 0)
			res[count - i] = ((10 - (n % 10)) % 10) + '0';
		else
			res[count - i - 1] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	return (res);
}
