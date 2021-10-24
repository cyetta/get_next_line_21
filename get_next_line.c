/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:14:13 by cyetta            #+#    #+#             */
/*   Updated: 2021/10/24 06:19:16 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE = 4096
#endif

char	*get_next_line(int fd)
{
	char		*dst;
	static int	cnt;

	if (!cnt)
		cnt = fd;
	if (--cnt)
		dst = ft_strdup("test\n");
	else
		dst = NULL;
	return (dst);
}
