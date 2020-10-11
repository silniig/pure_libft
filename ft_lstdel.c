#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*t;
	t_list	*s;

	if (!alst)
		return ;
	t = *alst;
	while (t)
	{
		s = t->next;
		ft_lstdelone(&t, del);
		t = s;
	}
	*alst = NULL;
}
