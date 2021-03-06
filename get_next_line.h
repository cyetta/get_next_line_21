/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:54:03 by cyetta            #+#    #+#             */
/*   Updated: 2021/11/05 18:24:08 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# include <stddef.h>

typedef struct s_fdesc
{
	int			fd;
	char		*buf;
	int			cnt;
}	t_fdesc;

char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
#endif
