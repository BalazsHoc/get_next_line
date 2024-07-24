/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:44:18 by bhocsak           #+#    #+#             */
/*   Updated: 2024/07/24 11:12:12 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

# if BUFFER_SIZE > 10000000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 10000000000
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*reading(int fd, char *growing_text);
char	*gnl_join_buffer(char *text, char *buffer);

int		gnl_strlen(char *str);
int		gnl_strchr(char *str, int c);
char	*gnl_strlcpy(char *str, int len);
void	gnl_fromnl(char *buf, char *str);
char	*endofile(char *text);

#endif
