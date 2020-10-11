#include "libft.h"

static size_t	ft_count_tokens(char const *s, char c)
{
	size_t	result;
	size_t	idx;
	size_t	cnt;

	idx = 0;
	result = 0;
	cnt = 0;
	while (s[idx])
	{
		while (s[idx + cnt] && s[idx + cnt] != c)
			cnt++;
		if (cnt > 0)
			result++;
		idx += cnt;
		cnt = 0;
		while (s[idx] && (s[idx] == c))
			idx++;
	}
	return (result);
}

static size_t	ft_next_token(char const *s, size_t *offset, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s[*offset + i] == c)
		i++;
	*offset += i;
	while (s[*offset + len] && s[*offset + len] != c)
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**r;
	size_t	count;
	size_t	idx;
	size_t	start;
	size_t	len;

	if (!s)
		return (NULL);
	count = ft_count_tokens(s, c);
	r = (char **)malloc((count + 1) * sizeof(char *));
	if (r == NULL)
		return (NULL);
	idx = 0;
	start = 0;
	len = 0;
	while (idx < count)
	{
		len = ft_next_token(s, &start, c);
		r[idx++] = ft_strsub(s, (unsigned int)start, len);
		start += len;
	}
	r[count] = NULL;
	return (r);
}
