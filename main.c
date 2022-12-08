/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:28:44 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/08 05:38:15 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include<stdio.h>
#include<fcntl.h>
int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *d = get_next_line(fd);
	char *e = get_next_line(fd);
	/*char *f = get_next_line(fd);
	char *h = get_next_line(fd);
	char *p = get_next_line(fd);
	char *s = get_next_line(fd);*/
	printf("%s", d);
	printf("%s", e);
	/*printf("%s", f);
	/*printf("%s", h);
	printf("%s", p);
	printf("%s", s);*/

	free(d);
	free(e);
	/*free(f);
	/*free(h);
	free(p);
	free(s);*/

	close(fd);
	return (0);
}
