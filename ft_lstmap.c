#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*r;
	t_list	**e;
	t_list	*fr;

	r = NULL;
	e = &r;
	while (lst != NULL)
	{
		fr = f(lst);
		if (fr == NULL)
			return (NULL);
		ft_lstadd(e, fr);
		e = &((*e)->next);
		lst = lst->next;
	}
	return (r);
}
