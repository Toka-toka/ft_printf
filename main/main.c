/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreeze <afreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 02:04:43 by afreeze           #+#    #+#             */
/*   Updated: 2020/05/20 17:25:09 by afreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		res;
	char	*s;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 1;
	while ((res = get_next_line(fd, &s)) == 1)
	{
		puts(s);
		free(s);
	}
	puts(s);
	printf("RES: %d\n", res);
	free(s);
	return (0);
}
