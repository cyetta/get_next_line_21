/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:14:13 by cyetta            #+#    #+#             */
/*   Updated: 2021/10/30 02:07:53 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif
/*
returns the actual file descriptor and pointer to it.
if it doesn't exist, creates fdesc and initializes it.
if an error occurred during creation, returns NULL
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

/* finds idx first char of next line in the fd->buf
if \n founds - returns idx next char after \n,
or retuns fd->cnt. if \n last char in fd-buf also
retuns fd->cnt
*/
size_t	find_nlidx(t_fdesc *fd)
{
	size_t	fdbuf_cnt;

	fdbuf_cnt = -1;
	while (++fdbuf_cnt < fd->cnt) //search \n & count idx
		if (fd->buf[fdbuf_cnt] == '\n')
			break ;
	if (fdbuf_cnt < fd->cnt) // if found \n return char idx of next string
		fdbuf_cnt++;
	return (fdbuf_cnt);
}

/*
Creates new string from str & fd->buf, like str_join
fdbuf_cnt - quantity char to copy from fd->buf, != 0
returns NULL on allocation error
the previose *str is released.
*/
char	*addbuff2str(char *str, t_fdesc *fd)
{
	char	*newstr;
	size_t	len;
	size_t	fdbuf_cnt;

	len = 0;
	if (str)
		len = ft_strlen(str);
	fdbuf_cnt = find_nlidx(fd);
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

	if (!createfdesc(&fdesc, fd))
		return (NULL);
	if (!fdesc->cnt)
		fdesc->cnt = read(fdesc->fd, fdesc->buf, BUFFER_SIZE); // read stream fdesc->fd to fdesc-buf, first init
	nextl = NULL;
	while (fdesc->cnt > 0) // try create nextl, while input flow isn`t empty
	{
		nextl = addbuff2str(nextl, fdesc);
		if (!nextl || nextl[ft_strlen(nextl) - 1] == '\n')
			break ;
		fdesc->cnt = read(fdesc->fd, fdesc->buf, BUFFER_SIZE);
	}
	if (!nextl) // read all data from fd, release memory and return (null)
	{
		free(fdesc->buf);
		free(fdesc);
	}
	return (nextl);
}
