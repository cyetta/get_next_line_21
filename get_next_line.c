/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:14:13 by cyetta            #+#    #+#             */
/*   Updated: 2021/11/02 01:48:06 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif
/*
returns the pointer to actual file descriptor
if it doesn't exist, creates fdesc and initializes it.
if an error occurred during creation, returns NULL
*/
static t_fdesc	*createfdesc(t_fdesc **fdesc, int fd)
{
	if (!(*fdesc))
	{
		*fdesc = (t_fdesc *)malloc(sizeof(t_fdesc));
		if (!(*fdesc))
			return (NULL);
		(*fdesc)->buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (!(*fdesc)->buf)
		{
			free(*fdesc);
			return (NULL);
		}
		(*fdesc)->fd = fd;
		(*fdesc)->cnt = 0;
	}
	return (*fdesc);
}

/*
Creates new string from str & fd->buf, like str_join
fdbuf_cnt - quantity char to copy from fd->buf, != 0
returns NULL on allocation error
the previose *str is released.
*/
static char	*addbuff2str(char *str, size_t *str_len, t_fdesc *fd)
{
	char	*newstr;
	int		fdbuf_cnt;

	fdbuf_cnt = 0;
	while (fdbuf_cnt < fd->cnt && fd->buf[fdbuf_cnt] != '\n')
		++fdbuf_cnt;
	if (fdbuf_cnt < fd->cnt)
		++fdbuf_cnt;
	newstr = (char *)malloc(*str_len + fdbuf_cnt + 1);
	if (newstr)
	{
		if (*str_len)
			ft_memcpy(newstr, str, *str_len);
		ft_memcpy(newstr + *str_len, fd->buf, fdbuf_cnt);
		newstr[*str_len + fdbuf_cnt] = '\0';
		if (fd->cnt - fdbuf_cnt)
			ft_memcpy(fd->buf, fd->buf + fdbuf_cnt, fd->cnt - fdbuf_cnt);
		fd->cnt -= fdbuf_cnt;
		*str_len += fdbuf_cnt;
	}
	if (str)
		free(str);
	return (newstr);
}

char	*get_next_line(int fd)
{
	static t_fdesc	*fdesc = NULL;
	char			*nextl;
	size_t			nextl_len;

	if (fd < 0 || BUFFER_SIZE <= 0 || !createfdesc(&fdesc, fd))
		return (NULL);
	if (!fdesc->cnt)
		fdesc->cnt = read(fdesc->fd, fdesc->buf, BUFFER_SIZE);
	nextl = NULL;
	nextl_len = 0;
	while (fdesc->cnt > 0)
	{
		nextl = addbuff2str(nextl, &nextl_len, fdesc);
		if (!nextl || nextl[nextl_len - 1] == '\n')
			break ;
		fdesc->cnt = read(fdesc->fd, fdesc->buf, BUFFER_SIZE);
	}
	if (!nextl)
	{
		free(fdesc->buf);
		free(fdesc);
		fdesc = NULL;
	}
	return (nextl);
}
