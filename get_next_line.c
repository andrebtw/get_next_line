/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:28:03 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/13 02:30:28 by anrodri2         ###   ########.fr       */
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
	r_string = (char *) malloc (ft_strlen(s, 0) - ft_strlen(s, 1) + 1);
	if (!r_string)
	{
		if (is_saved_string)
			free(s);
		return (NULL);
	}
	j = 0;
	while (s[i])
		r_string[j++] = s[i++];
	free(s);
	r_string[j] = '\0';
	return (r_string);
}

char	*save_static(char *temp_string, char *stash,
		char *saved_string, int read_output)
{
	if (!read_output && (!stash || !stash[0]))
	{
		free(temp_string);
		free(saved_string);
		saved_string = NULL;
		return (NULL);
	}
	if (read_output != NOT_READ)
	{
		free(saved_string);
		saved_string = NULL;
		saved_string = back_up_string(temp_string, 0);
		if (!saved_string)
			return (free(temp_string), free(stash), free(saved_string), NULL);
	}
	else
	{
		saved_string = back_up_string(saved_string, 1);
		if (!saved_string)
			return (free(temp_string), free(stash), free(saved_string), NULL);
		free(temp_string);
	}
	return (saved_string);
}

char	*main_func(int fd, char *r_s, char *temp_s, int free_static)
{
	int		found_n;
	int		read_output;
	static char *savd_s;

	if (!savd_s)
		savd_s = (char *) ft_calloc(1, sizeof(char));
	if (!savd_s || free_static)
		return (free(savd_s), savd_s = NULL, NULL);
	found_n = 0;
	r_s = ft_strjoin(r_s, savd_s);
	if (!r_s)
		return (free(temp_s), free(savd_s), savd_s = NULL, NULL);
	if (ft_strlen(savd_s, 0) != ft_strlen(savd_s, 1))
		found_n = 1;
	read_output = NOT_READ;
	while (!found_n)
	{
		free(temp_s);
		temp_s = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!temp_s)
			return (free(r_s), free(savd_s), savd_s = NULL, NULL);
		read_output = read(fd, temp_s, BUFFER_SIZE);
		if (read_output == -1)
			return (free(temp_s), free(r_s), free(savd_s), savd_s = NULL, NULL);
		if (ft_strlen(temp_s, 0) != ft_strlen(temp_s, 1) || read_output == 0)
			found_n = 1;
		r_s = ft_strjoin(r_s, temp_s);
		if (!r_s)
			return (free(temp_s), free(savd_s), savd_s = NULL, NULL);
	}
	savd_s = save_static(temp_s, r_s, savd_s, read_output);
	return (r_s);
}

char	*get_next_line(int fd)
{
	char		*temp_s;
	char		*r_s;

	r_s = (char *) ft_calloc(1, sizeof(char));
	temp_s = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if ((!r_s || !temp_s))
		return (r_s = failed_malloc(NULL, r_s, temp_s),
			temp_s = main_func(0, NULL, NULL, 1), NULL);
	r_s = main_func(fd, r_s, temp_s, 0);
	if (!r_s)
		return (r_s = main_func(0, NULL, NULL, 1), NULL);
	if (r_s && !r_s[0])
		return (free(r_s), NULL);
	return (r_s);
}
