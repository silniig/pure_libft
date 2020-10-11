/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcody <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:31:01 by gcody             #+#    #+#             */
/*   Updated: 2019/11/19 21:55:02 by gcody            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		rdr_equal(void *fst, size_t fstsz, void *snd, size_t sndsz)
{
	if (!fstsz || !sndsz)
		return (0);
	if (((t_reader *)snd)->fd == *((int *)fst))
		return (1);
	return (0);
}

static t_reader	*find_reader(t_list **lst, int fd)
{
	t_reader	*res;
	t_list		*found;

	if (*lst && (found = ft_lstfind(*lst, (void *)&fd, sizeof(int), rdr_equal)))
		return (t_reader *)(found->content);
	if (fd < 0 || !(res = (t_reader *)malloc(sizeof(t_reader))))
		return (NULL);
	res->fd = fd;
	res->offset = 0;
	res->end = 0;
	found = ft_lstnew((void *)res, sizeof(t_reader));
	free(res);
	if (!found)
		return (NULL);
	((t_reader *)found->content)->buf = (char *)malloc(BUFF_SIZE);
	if (!((t_reader *)found->content)->buf)
	{
		free(found);
		return (NULL);
	}
	ft_lstadd(lst, found);
	return ((t_reader *)found->content);
}

static int		read_line(t_reader *rd, t_list **line)
{
	int		c;
	t_list	*ch;

	while (1)
	{
		c = 0;
		while ((rd->offset + c < rd->end) && (rd->buf[rd->offset + c] != '\n'))
			c++;
		if (c > 0 || (rd->offset + c < rd->end))
		{
			ch = ft_lstnew(rd->buf + rd->offset, c);
			if (!ch || !(ch->content))
				break ;
			ft_lstadd(line, ch);
			rd->offset += (c + 1);
			if (rd->offset - 1 < rd->end)
				return (1);
		}
		if ((rd->end = read(rd->fd, rd->buf, BUFF_SIZE)) < 1)
			return (rd->end);
		rd->offset = 0;
	}
	ft_lstdelone(&ch, NULL);
	return (-1);
}

static int		pack_line(char **line, t_list **str, int end)
{
	size_t	len;
	t_list	*lst;

	lst = *str;
	len = 0;
	while (lst)
	{
		len += lst->content_size;
		lst = lst->next;
	}
	if (!(*line = (char *)malloc(len + 1)))
		return (-1);
	lst = *str;
	(*line)[len] = '\0';
	while (lst)
	{
		ft_memcpy(*line + (len - lst->content_size), lst->content,
					lst->content_size);
		len -= lst->content_size;
		lst = lst->next;
	}
	ft_lstdel(str, NULL);
	return (end);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*fds = NULL;
	t_reader		*reader;
	t_list			*lnl;
	t_list			*lstr;
	int				end;

	lnl = NULL;
	reader = find_reader(&fds, fd);
	if ((BUFF_SIZE < 1) || (!reader) || (!line))
		return (-1);
	end = read_line(reader, &lnl);
	if (end != 1)
	{
		lstr = ft_lstunlink(&fds, &(reader->fd), sizeof(int), rdr_equal);
		free(((t_reader *)(lstr->content))->buf);
		ft_lstdelone(&lstr, NULL);
		if (end == -1)
			return (-1);
		end = (lnl) ? 1 : 0;
	}
	end = (end == 1) ? (pack_line(line, &lnl, end)) : end;
	return (end);
}
