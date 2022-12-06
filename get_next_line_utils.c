/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:31:43 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/06 05:11:19 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char			*return_string;
	unsigned int	i;
	unsigned int	string_size;

	string_size = 0;
	while (s[string_size] != '\0')
		string_size++;
	return_string = (char *) malloc(string_size * sizeof(char) + 1);
	if (return_string == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		return_string[i] = s[i];
		i++;
	}
	return_string[i] = '\0';
	return (return_string);
}

size_t	ft_strlen_int(char *s, int check_if_endl)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (check_if_endl && s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*r_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	r_string = (char *) malloc (ft_strlen_int(s1, 0) + ft_strlen_int(s2, 1) + 1);
	if (r_string == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		r_string[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0' && s2[i - 1] != '\n')
	{
		r_string[j] = s2[i];
		i++;
		j++;
	}
	r_string[j] = '\0';
	return (r_string);
}
