/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:21:42 by msapin            #+#    #+#             */
/*   Updated: 2023/11/26 14:26:11 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd = open("fd.txt", O_RDONLY);

	int i;
	char * line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break;
		printf("%s\n", line);
	}
	return (0);
}
