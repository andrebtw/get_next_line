/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:28:03 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/06 05:08:16 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*temp_string;
	static char	*saved_string;
	char		*stash;
	int			read_output;
	int			found_n;

	found_n = 0;
	temp_string = ft_strdup("");
	stash = ft_strdup("");
	if (!temp_string || !stash)
		return (NULL);
	while (!found_n)
	{
		read_output = read(fd, temp_string, BUFFER_SIZE);
		if (read_output == -1)
			return (NULL);
		stash = ft_strjoin(stash, temp_string);
		if (ft_strlen_int(temp_string, 0) != ft_strlen_int(temp_string, 1) || read == 0)
			found_n = 1;
	}
	return (stash);
}
