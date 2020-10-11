#include "libft.h"

t_list	*ft_lstfind(t_list *lst, void *content, size_t size,
					int (*eq)(void *, size_t, void *, size_t))
{
	while (lst)
	{
		if (eq)
		{
			if (eq(content, size, lst->content, lst->content_size))
				return (lst);
		}
		else if (ft_memcmp(content, lst->content, size) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
