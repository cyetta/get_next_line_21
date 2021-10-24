/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:58:59 by cyetta            #+#    #+#             */
/*   Updated: 2021/10/24 02:04:48 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		++len;
	return (len);
}

/*
Создает дубликат строки s1 и возвращает указатель на нее
*/
char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*dst;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (!dst)
		return (dst);
	i = -1;
	while (++i < len)
		dst[i] = s[i];
	dst[i] = '\0';
	return (dst);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = -1;
	while (++i < n)
		((char *)dst)[i] = ((char *)src)[i];
	return (dst);
}
