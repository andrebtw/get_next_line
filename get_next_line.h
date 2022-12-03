/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:28:33 by anrodri2          #+#    #+#             */
/*   Updated: 2022/12/02 20:02:48 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// SIGNALS //
# define ENDL_NOT_FOUND -1

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2, size_t size, size_t start);
int		ft_strlen_int(const char *s);
void	*ft_calloc(size_t count, size_t size);

#endif