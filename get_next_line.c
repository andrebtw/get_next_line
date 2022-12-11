/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:28:03 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/11 10:24:04 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*back_up_string(char *s, int is_saved_string)
{
	int		i;
	int		j;
	char	*r_string;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i])
		i++;
	r_string = (char *) malloc (ft_strlen_int(s, 0) - ft_strlen_int(s, 1) + 1);
	if (!r_string)
	{
		if (is_saved_string)
			free(s);
		return (NULL);
	}
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

int	check_if_endf(char *s, int read_value)
{
	if (!read_value && (!s || !s[0]))
		return (1);
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
	stash = (char *) ft_calloc(1, sizeof(char));
	if (!stash)
	{
		if (saved_string)
		{
			free(saved_string);
			saved_string = NULL;
		}
		return (NULL);
	}
	temp_string = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_string)
		return (free(stash), free(saved_string), saved_string = NULL, NULL);
	if (!saved_string)
		saved_string = (char *) ft_calloc(1, sizeof(char));
	if (!saved_string)
		return (free(stash), free(temp_string), NULL);
	if (saved_string && saved_string[0])
	{
		stash = ft_strjoin(stash, saved_string);
		if (!stash)
			return (free(temp_string), free(saved_string), saved_string = NULL, NULL);
		if (ft_strlen_int(saved_string, 0) != ft_strlen_int(saved_string, 1))
			found_n = 1;
	}
	read_output = -10;
	while (!found_n)
	{
		free(temp_string);
		temp_string = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!temp_string)
			return (free(stash), free(saved_string), saved_string = NULL, NULL);
		read_output = read(fd, temp_string, BUFFER_SIZE);
		if (read_output == -1)
			return (free(temp_string), free(stash), free(saved_string), saved_string = NULL, NULL);
		if (ft_strlen_int(temp_string, 0) != ft_strlen_int(temp_string, 1) || read_output == 0)
			found_n = 1;
		stash = ft_strjoin(stash, temp_string);
		if (!stash)
			return (free(temp_string), free(saved_string), saved_string = NULL, NULL);
	}
	if (check_if_endf(stash, read_output))
	{
		free(temp_string);
		free(saved_string);
		saved_string = NULL;
		if (stash)
			free(stash);
		return (NULL);
	}
	if (read_output != -10)
	{
		free(saved_string);
		saved_string = NULL;
		saved_string = back_up_string(temp_string, 0);
		if (!saved_string)
			return (free(temp_string), free(stash), free(saved_string), saved_string = NULL, NULL);
	}
	else
	{
		saved_string = back_up_string(saved_string, 1);
		if (!saved_string)
			return (free(temp_string), free(stash), free(saved_string), saved_string = NULL, NULL);
		free(temp_string);
	}
	return (stash);
}
