
#include "get_next_line.h"

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

    if (!text)
        joined = (char *)malloc(sizeof(char) * (gnl_strlen(buffer) + 1));
    else
        joined = (char *)malloc(sizeof(char) * (gnl_strlen(text) + gnl_strlen(buffer) + 1));
    if (!joined)
        return (NULL);
    if (text[0])
    {
        while (text[i++])
            joined[i] = text[i];
    }
    while (buffer[j++])
        joined[i + j] = buffer[j];
    joined[i + j] = '\0';
    return (joined);
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
        while (str[len] != 0 && str[len] != '\n')
            len++;
        line = (char *)malloc(sizeof(char) * (len + 1));
        if (!line)
            return (NULL);
        line[len + 1] = '\0';
        while (len--)
            line[len] = str[len];
        return (line);
    }
    len = gnl_strlen(str);
    line = (char *)malloc(sizeof(char) * (len + 1));
        if (!line)
            return (NULL);
    line[len + 1] = '\0';
    while (len--)
            line[len] = str[len];
    return (line);
}