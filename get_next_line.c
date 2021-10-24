/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:14:13 by cyetta            #+#    #+#             */
/*   Updated: 2021/10/24 19:29:22 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif
/*
Returnt actual filedescriptor and pointer to fl_desc
if not exist, Create fl_desc and init it.
in creation error return NULL
*/
fl_desc	*createfdesc(fl_desc **fdesc, int fd)
{
	if (!(*fdesc))
	{
		*fdesc = (fl_desc *)malloc(sizeof(fl_desc));
		if (!(*fdesc))
			return (NULL);
		(*fdesc)->buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (!(*fdesc)->buf)
		{
			free(*fdesc);
			return (NULL);
		}
		(*fdesc)->fd = fd;
		(*fdesc)->idx = 0;
	}
	return (*fdesc);
}

char	*get_next_line(int fd)
{
	static fl_desc	*fdesc;

	if (!createfdesc(&fdesc, fd))
		return (NULL);

	return (NULL);
}
