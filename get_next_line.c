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

void	*gnl_calloc(size_t nmemb, size_t size)
{
	void	*buffer;
	size_t	i;
	size_t	len;

	i = 0;
	len = nmemb * size + 1;
	if (!nmemb || !size)
		return (NULL);
	if (size > SIZE_MAX / nmemb)
		return (NULL);
	buffer = (void *)malloc(len);
	if (!buffer)
		return (NULL);
	while (i < len)
	{
		((char *)buffer)[i] = '\0';
		i++;
	}
	return (buffer);
}

char	*gnl_join_free(char *static_buf, char *buffer, int retur_of_read)
{
	char	*previous;

	if (retur_of_read <= 0)
	{
		free(static_buf);
		if (retur_of_read == -1)
			return (free(buffer), NULL);
	}
	else
	{
		previous = static_buf;
		static_buf = gnl_join_buffer(previous, buffer);
		free(previous);
		free(buffer);
	}
	if (!static_buf)
		return (NULL);
	return (static_buf);
}

char	*gnl_join_buffer(char *line, char *buffer)
{
	char	*joined;
	int		i;
	int		j;

	if (!line && !buffer)
		return (NULL);
	joined = (char *)gnl_calloc((gnl_strlen(line)
				+ gnl_strlen(buffer) + 1), sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	while (line && line[i] != '\0')
	{
		joined[i] = line[i];
		i++;
	}
	j = 0;
	while (buffer && buffer[j] != '\0')
	{
		joined[i + j] = buffer[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}

char	*reading(int fd, char *static_buf)
{
	char	*buffer;
	ssize_t	return_of_read;

	if (!static_buf)
		static_buf = gnl_calloc(1, 1);
	if (!static_buf)
		return (NULL);
	while (!gnl_newline(static_buf))
	{
		buffer = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (free(static_buf), NULL);
		return_of_read = read(fd, buffer, BUFFER_SIZE);
		if (return_of_read == 0)
		{
			free(buffer);
			break ;
		}
		buffer[return_of_read] = '\0';
		static_buf = gnl_join_free(static_buf, buffer, return_of_read);
		if (!static_buf)
			return (NULL);
	}
	return (static_buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*output;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = reading(fd, buf);
	if (!buf)
		return (NULL);
	output = gnl_strcpy(buf);
	if (!output)
		return (free(buf), NULL);
	if (gnl_newline(buf) == 1)
	{
		buf = gnl_fromnl(buf);
		return (output);
	}
	return (free(buf), output);
}
// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *line = get_next_line(fd);

// 	while (1)
// 	{
// 		printf("line: %s", line);
// 		if (!line)
// 			break ;
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return 0;
// }