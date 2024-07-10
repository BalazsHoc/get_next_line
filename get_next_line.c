
#include "get_next_line.h"

char    *reading(int fd, char *static_buf)
{
    char        *buffer;
    ssize_t     return_of_read;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    buffer[BUFFER_SIZE] = '\0';
    return_of_read = 1;
    while (return_of_read > 0)
    {
        return_of_read = read(fd, buffer, BUFFER_SIZE);
        if (return_of_read == -1)
            return (free(buffer), NULL);
        if (gnl_strchr(buffer, '\n') != -1)
        {
            static_buf = gnl_join_buffer(static_buf, buffer);
            break ;
        }
        static_buf = gnl_join_buffer(static_buf, buffer);
    }
    free(buffer);
    return (static_buf);
}

char    *gnl_join_buffer(char *text, char *buffer)
{
    char    *joined;
    int     i;
    int     j;

    i = 0;
    j = 0;

    joined = (char *)malloc(sizeof(char) * (gnl_strlen(text) + gnl_strlen(buffer)) + 1);
    if (!joined)
        return (NULL);
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

char    *get_next_line(int fd)
{
    static char     *buf;
    char            *output;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    if (!buf)
        buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);    
    buf = reading(fd, buf);
    if (!buf)
        return (NULL);
    if (gnl_strchr(buf, '\n') == -1)
    {
        output = gnl_strlcpy(buf, gnl_strlen(buf) + 1);
        return (free(buf), output);
    }

    output = gnl_strlcpy(buf, gnl_strchr(buf, '\n'));
    if (!output)
        return (free(buf), NULL);
    buf = gnl_fromnl(buf);
    printf("rest: %s\n", buf);
    if (!buf)
        return (free(output), NULL);
    return (output);
}

#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd = open("file.txt", O_RDONLY);

    printf("return: %s\n----------\n", get_next_line(fd));

    printf("return: %s", get_next_line(fd));
    return (0);
}