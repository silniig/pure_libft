#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst != NULL && *alst != NULL)
	{
		if (del)
			del((*alst)->content, (*alst)->content_size);
		else
			free((*alst)->content);
		free(*alst);
		*alst = NULL;
	}
}
