/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:44:18 by bhocsak           #+#    #+#             */
/*   Updated: 2024/07/28 13:27:02 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

char	*get_next_line(int fd);
char	*reading(int fd, char *static_buf);
char	*gnl_join_buffer(char *line, char *buffer);
char	*gnl_join_free(char	*buffer, char *static_buf, int return_of_read);
void	*gnl_calloc(size_t nmemb, size_t size);

char	*gnl_fromnl(char *str);
char	*gnl_strcpy(char *str);
int		gnl_newline(char *str);
int		gnl_strlen(char *str);

#endif
