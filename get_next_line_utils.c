/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:40:00 by bhocsak           #+#    #+#             */
/*   Updated: 2024/07/22 08:43:48 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	gnl_strchr(char *str, int c)
{
	int	here;

	here = 0;
	while (str[here] != c)
	{
		if (!str[here])
			return (-1);
		here++;
	}
	return (here);
}

char	*gnl_strlcpy(char *str, int len)
{
	char	*copied;
	int		i;

	i = 0;
	copied = (char *)malloc(sizeof(char) * (len) + 1);
	if (!copied)
		return (NULL);
	while (i < len)
	{
		copied[i] = str[i];
		i++;
	}
	copied[len] = '\0';
	return (copied);
}

void	gnl_fromnl(char *buf, char *str)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	start = gnl_strchr(str, '\n') + 1;
	end = gnl_strlen(str);
	if (start == -1 || end == 0)
		return (free(str));
	while (start < end)
	{
		buf[i] = str[start];
		start++;
		i++;
	}
	buf[i] = '\0';
	free(str);
}

char	*endofile(char *text)
{
	char	*output;

	output = gnl_strlcpy(text, gnl_strlen(text));
	if (!output)
		return (free(text), NULL);
	if (output[0] == '\0')
		return (free(text), free(output), NULL);
	return (free(text), output);
}
