/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:59:30 by cyetta            #+#    #+#             */
/*   Updated: 2021/10/30 03:29:19 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argv, char **argc)
{
	char	*newline;
	int		handle;

	if (argv == 2)
	{
		printf("arg[1] - %s\n", argc[1]);
		handle = open(argc[1], O_RDWR);
		if (handle < 0)
			return (2);
		newline = get_next_line(handle);
		while (newline)
		{
			printf("%s", newline);
			free(newline);
			newline = get_next_line(handle);
		}
		close(handle);
		return (0);
	}
	return (1);
}
