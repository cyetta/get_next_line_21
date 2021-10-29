/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:54:03 by cyetta            #+#    #+#             */
/*   Updated: 2021/10/27 00:51:56 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>

typedef struct s_fdesc
{
	int			fd;
	char		*buf;
	ssize_t		cnt;
}	t_fdesc;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
#endif
