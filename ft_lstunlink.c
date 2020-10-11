#include "libft.h"

static int	equal(t_list *node, void *content, size_t size,
			int (*eq)(void *, size_t, void *, size_t))
{
	if (eq)
	{
		if (eq(content, size, node->content, node->content_size))
			return (1);
		return (0);
	}
	return ((ft_memcmp(content, node->content, size) == 0) ? 1 : 0);
}

t_list		*ft_lstunlink(t_list **alst, void *content, size_t size,
						int (*eq)(void *, size_t, void *, size_t))
{
	t_list	*mov;
	t_list	*res;

	mov = *alst;
	if (equal(mov, content, size, eq))
	{
		res = *alst;
		*alst = (*alst)->next;
		return (res);
	}
	while (mov->next)
	{
		if (equal(mov->next, content, size, eq))
		{
			res = mov->next;
			mov->next = mov->next->next;
			return (res);
		}
	}
	return (NULL);
}
