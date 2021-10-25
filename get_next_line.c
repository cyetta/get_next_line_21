/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:14:13 by cyetta            #+#    #+#             */
/*   Updated: 2021/10/25 22:14:41 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif
/*
Returnt actual filedescriptor and pointer to t_fdesc
if not exist, Create t_fdesc and init it.
in creation error return NULL
*/
t_fdesc	*createfdesc(t_fdesc **fdesc, int fd)
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
Create new string from str & fd->buf, like str_join
fdbuf_cnt - quantity char to copy from fd->buf, != 0
*/
char	*addbuff2str(char *str, t_fdesc *fd, ssize_t fdbuf_cnt)
{
	char	*newstr;
	size_t	len;
	size_t	i;

	len = 0;
	if (str)
		len = ft_strlen(str);
	newstr = (char *)malloc(len + fdbuf_cnt + 1);
	if (newstr)
	{
		if (len)
			ft_memcpy(newstr, str, len);
		ft_memcpy(newstr + len, fd->buf, fdbuf_cnt);
		newstr[len + fdbuf_cnt + 1] = '\0';
		ft_memcpy(fd->buf, fd->buf + fdbuf_cnt, fd->cnt - fdbuf_cnt);
		fd->cnt -= fdbuf_cnt;
	}
	if (str)
		free(str);
	return (newstr);
}

char	*get_next_line(int fd)
{
	static t_fdesc	*fdesc = NULL;
	char			*nextl;
	ssize_t			n_idx;

	if (!createfdesc(&fdesc, fd))
		return (NULL);
	if (!fdesc->cnt)
		fdesc->cnt = read(fdesc->fd, fdesc->buf, BUFFER_SIZE); // read stream fdesc->fd to fdesc-buf, first init
	nextl = NULL;
	while (fdesc->cnt) // try create nextl, while input flow isn`t empty
	{
		n_idx = -1;
		while (++n_idx < fdesc->cnt) //search \n & count length
			if (fdesc->buf[n_idx] == '\n')
				break ;
		if (n_idx < fdesc->cnt) // if found \n return string
			return (addbuff2str(nextl, fdesc, n_idx + 1));
		nextl = addbuff2str(nextl, fdesc, n_idx); // append buff to string & continue search \n
		if (!nextl)
			return (nextl);
		fdesc->cnt = read(fdesc->fd, fdesc->buf, BUFFER_SIZE);
	}
	// read all data from fd, release memory and return (null)
}
