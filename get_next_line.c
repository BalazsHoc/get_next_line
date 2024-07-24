/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:33:25 by bhocsak           #+#    #+#             */
/*   Updated: 2024/07/22 09:04:17 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_join_buffer(char *text, char *buffer)
{
	char	*joined;
	int		i;
	int		j;

	i = 0;
	j = 0;
	joined = (char *)malloc(sizeof(char) * (gnl_strlen(text)
				+ gnl_strlen(buffer)) + 1);
	if (!joined)
		return (free(text), NULL);
	while (i < gnl_strlen(text))
	{
		joined[i] = text[i];
		i++;
	}
	while (j < gnl_strlen(buffer))
	{
		joined[i + j] = buffer[j];
		j++;
	}
	joined[i + j] = '\0';
	return (free(text), joined);
}

char	*reading(int fd, char *static_buf)
{
	char	*buffer;
	ssize_t	return_of_read;

	buffer = gnl_strlcpy(static_buf, gnl_strlen(static_buf));
	if (!buffer)
		return (NULL);
	return_of_read = read(fd, static_buf, BUFFER_SIZE);
	while (return_of_read > 0)
	{
		static_buf[return_of_read] = '\0';
		buffer = gnl_join_buffer(buffer, static_buf);
		if (!buffer)
			return (NULL);
		if (gnl_strchr(buffer, '\n') != -1)
			break ;
		return_of_read = read(fd, static_buf, BUFFER_SIZE);
	}
	if (return_of_read == -1)
	{
		static_buf[0] = '\0';
		return (free(buffer), NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*text;
	char		*output;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	text = reading(fd, buf);
	if (!text)
		return (NULL);
	if (gnl_strchr(text, '\n') == -1)
	{
		buf[0] = '\0';
		return (endofile(text));
	}
	output = gnl_strlcpy(text, gnl_strchr(text, '\n') + 1);
	if (!output)
		return (free(text), NULL);
	gnl_fromnl(buf, text);
	return (output);
}
// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *line = get_next_line(fd);

// 	while (1)
// 	{
// 		if (!line)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	return 0;
// }