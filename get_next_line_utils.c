/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:31:43 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/11 10:56:25 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*array;
	size_t			i;
	size_t			k;

	k = 0;
	if (size)
		if (SIZE_MAX / size <= count)
			return (NULL);
	array = (unsigned char *) malloc ((count * size));
	if (array == NULL)
		return (NULL);
	i = count * size;
	while (k < i)
	{
		array[k] = '\0';
		k++;
	}
	return ((void *)array);
}

size_t	ft_strlen_int(const char *s, int check_if_endl)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
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
	if (ft_strlen_int(s2, 0) == ft_strlen_int(s2, 1))
		r_string = (char *) malloc (
				ft_strlen_int(s1, 0) + ft_strlen_int(s2, 1) + 1);
	else
		r_string = (char *) malloc (
				ft_strlen_int(s1, 0) + ft_strlen_int(s2, 1) + 2);
	if (r_string == NULL)
		return (free(s1), NULL);
	while (s1[i] != '\0')
		r_string[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0' && s2[i] != '\n')
		r_string[j++] = s2[i++];
	if (s2[i] == '\n')
		r_string[j++] = '\n';
	return (free(s1), r_string[j] = '\0', r_string);
}
