/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:59:30 by cyetta            #+#    #+#             */
/*   Updated: 2021/10/24 06:16:29 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argv, char **argc)
{
	char	*newline;

	if (argv == 2)
	{
		printf("arg[1] - %s\n", argc[1]);
		newline = get_next_line(5);
		while (newline)
		{
			printf("%s", newline);
			free(newline);
			newline = get_next_line(5);
		}
	}
}
