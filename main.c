/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:28:44 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/13 03:45:36 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<fcntl.h>
#include<stdio.h>

int	main(void)
{
	char	*string;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	while (string != NULL)
	{
		string = get_next_line(84);
		printf("%s", string);
		free(string);
	}
	close(fd);
	return (0);
}