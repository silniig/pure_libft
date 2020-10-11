#include "libft.h"

static size_t	ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static size_t	ft_count_preceding_whitespaces(char const *s)
{
	size_t	r;

	r = 0;
	while (s[r] != '\0' && (ft_is_whitespace(s[r])))
		r++;
	return (r);
}

static size_t	ft_count_trailing_whitespaces(char const *s, size_t len)
{
	size_t	r;

	r = 0;
	while ((len > r + 1) && ft_is_whitespace(s[len - r - 1]))
		r++;
	return (r);
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	beg;
	size_t	end;
	char	*result;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	beg = ft_count_preceding_whitespaces(s);
	end = ft_count_trailing_whitespaces(s, len);
	if (len == beg)
		return (ft_strnew(0));
	result = ft_strnew(len - beg - end);
	if (result == NULL)
		return (NULL);
	return (ft_memcpy(result, (s + beg), (len - beg - end)));
}
