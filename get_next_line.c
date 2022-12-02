/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:28:03 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/01 19:40:26 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_if_endl(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (i);
		i++;
	}
	return (ENDL_NOT_FOUND);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*temp_string;
	int			found_n;

	found_n = 0;
	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	while (!found_n)
	{
		temp_string = ft_calloc(BUFFER_SIZE, sizeof(char));
		if (read(fd, stash, BUFFER_SIZE) == -1)
			return (NULL);
		if (check_if_endl(temp_string) != ENDL_NOT_FOUND)
		{
			stash = ft_strjoin(stash, temp_string, check_if_endl(temp_string));
			found_n = 1;
		}
		stash = ft_strjoin(stash, temp_string, ft_strlen_int(temp_string));
	}
	return (stash);
}
