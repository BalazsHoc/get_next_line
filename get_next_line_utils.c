
#include "get_next_line.h"

void    ft_free(char *str)
{
    while (str)
    {
        free(str);
        str = NULL;
        str++;
    }
}

int  gnl_strlen(char *str)
{
    int  len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

char    *gnl_join_buffer(char *text, char *buffer)
{
    char    *joined;
    int     i;
    int     j;

    i = 0;
    j = 0;
    joined = (char *)malloc(sizeof(char) * (gnl_strlen(text) + gnl_strlen(buffer) + 1));
    if (!joined)
        return (ft_free(joined), NULL);
    while (text[i++])
        joined[i] = text[i];
    while (buffer[j++])
        joined[i + j] = buffer[j];
    joined[i + j] = '\0';
    return (ft_free(text), joined);
}

int    gnl_strchr(char *str, int c)
{
    int i;

    i = 0;
    while (str[i] != c)
    {
        if (!str[i])
            return (0);
        i++;
    }
    return (1);
}

char    *gnl_strdup(char *str, int c)
{
    int     len;
    char    *line;

    len = 0;
    if (c == 1)
    {
        while (str[len] && str[len] != '\n')
            len++;
        line = (char *)malloc(sizeof(char) * (len + 1));
        if (!line)
            return (ft_free(line), NULL);
        line[len] = '\0';
        while (line[len--])
            line[len] = str[len];
        return (line);
    }
    len = gnl_strlen(str);
    line = (char *)malloc(sizeof(char) * (len + 1));
        if (!line)
            return (ft_free(line), NULL);
    line[len--] = '\0';
    while (line[len--])
            line[len] = str[len];
    return (line);
}