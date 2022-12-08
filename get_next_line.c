/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:28:03 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/08 06:02:04 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*back_up_string(char *s, char *saved_string)
{
	int		i;
	int		j;
	char	*r_string;

	i = 0;
	free(saved_string);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i])
		i++;
	r_string = (char *) malloc (ft_strlen_int(s, 0) - ft_strlen_int(s, 1) + 1);
	if (!r_string)
		return (NULL);
	j = 0;
	while (s[i])
	{
		r_string[j] = s[i];
		j++;
		i++;
	}	
	free(s);
	r_string[j] = '\0';
	return (r_string);
}

int	check_if_endf(char *s, int read_value, char *temp_str, char *saved_string)
{
	if (!read_value && (!s || !s[0]))
	{
		free(s);
		free(temp_str);
		free(saved_string);
		return (1);
	}
	return (0);	
}

char	*get_next_line(int fd)
{
	char		*temp_string;
	static char	*saved_string;
	char		*stash;
	int			read_output;
	int			found_n;

	found_n = 0;
	if (ft_strlen_int(saved_string, 0) != ft_strlen_int(saved_string, 1))
		found_n = 1;
	stash = (char *) ft_calloc(1, sizeof(char));
	if (!saved_string)
		saved_string = (char *) ft_calloc(1, sizeof(char));
	if (!stash || !saved_string)
		return (NULL);
	if (saved_string[0])
		stash = ft_strjoin(stash, saved_string);
	read_output = -10;
	while (!found_n)
	{
		temp_string = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!temp_string)
			return (NULL);
		read_output = read(fd, temp_string, BUFFER_SIZE);
		if (read_output == -1)
			return (NULL);
		if (ft_strlen_int(temp_string, 0) != ft_strlen_int(temp_string, 1) || read_output == 0)
			found_n = 1;
		stash = ft_strjoin(stash, temp_string);
		if (!found_n)
			free(temp_string);
	}
	if (check_if_endf(stash, read_output, temp_string, saved_string))
		return (NULL);
	if (read_output != -10)
		saved_string = back_up_string(temp_string, saved_string);
	else
		saved_string = back_up_string(saved_string, saved_string);
	return (stash);
}
