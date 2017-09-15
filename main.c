/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:53:00 by enunes            #+#    #+#             */
/*   Updated: 2017/08/08 19:51:20 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			printf("%s\n", line);
		}
	}
	return (0);
}
