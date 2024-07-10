
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

char *gnl_strcpy(char *str, int start, int end)
{
    char    *copied;

    if (start > end)
        return (NULL);
    copied = (char *)malloc(sizeof(char) * (end - start + 1));
    if (!copied)
        return (NULL);
    while (start < end)
    {
        copied[start] = str[start];
        start++;
    }
    copied[end + 1] = '\0';
    return (copied);
}