
#include "get_next_line.h"

int  gnl_strlen(char *str)
{
    int  len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

int    gnl_strchr(char *str, int c)
{
    int here;

    here = 0;
    while (str[here] != c)
    {
        if (!str[here])
            return (-1);
        here++;
    }
    return (here);
}

char *gnl_strlcpy(char *str, int len)
{
    char    *copied;
    int     i;

    i = 0;
    copied = (char *)malloc(sizeof(char) * (len) + 1);
    if (!copied)
        return (NULL);
    while (i <= len)
    {
        copied[i] = str[i];
        i++;
    }
    copied[len + 1] = '\0';
    return (copied);
}

char    *gnl_fromnl(char *str)
{
    int     i;
    int     start;
    int     end;
    char    *line;

    i = 0;
    start = gnl_strchr(str, '\n') + 1;
    end = gnl_strlen(str) + 1;
    if (start == end)
        return (free(str), NULL);
    line = (char *)malloc(sizeof(char) * (end - start) + 1);
    if (!line)
        return (NULL);
    while (start <= end)
    {
        line[i] = str[start];
        start++;
        i++;
    }
    line[start] = '\0';
    return (free(str), line);
}