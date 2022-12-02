/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:28:44 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/01 19:29:33 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include<stdio.h>
#include<fcntl.h>
int	main(void)
{
	int fd = open("test.txt", O_RDONLY | O_CREAT);
	char *hello = get_next_line(fd);
	return (0);
}
