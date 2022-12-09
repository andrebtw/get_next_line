/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:28:44 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/09 17:01:39 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include<stdio.h>
#include<fcntl.h>
int	main(void)
{
	char	*string;

	int fd = open("test.txt", O_RDONLY);
	while (string != NULL)
	{
		string = get_next_line(fd);
		printf("%s", string);
	}
	close(fd);
	return (0);
}
