/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:28:03 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/02 20:07:28 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_if_endl(char *string, size_t n_times)
{
	int	i;

	while (string[i])
	{
		if (string[i] == '\n')
		{
			if (!n_times)
				return (i);
			n_times--;
		}
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	static size_t	n_times;
	char			*temp_string;	
	int				found_n;

	found_n = 0;
	if (!stash)
	{
		stash = ft_calloc(1, sizeof(char));
		n_times = 0;
	}
	while (!found_n)
	{
		temp_string = ft_calloc(BUFFER_SIZE, sizeof(char));
		if (read(fd, temp_string, BUFFER_SIZE) == -1)
			return (NULL);
		stash = ft_strjoin(stash, temp_string, ft_strlen_int(temp_string));
		if (check_if_endl(stash, n_times))
			found_n = 1;
	}
	n_times++;
	return (stash);
}
