
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
        printf("return of read: %zd\n", return_of_read);
        if (return_of_read == -1)
            return (free(buffer), NULL);
        if (gnl_strchr(buffer, '\n') != -1)
        {
            static_buf = gnl_join_buffer(static_buf, buffer);
            printf("after readings buf: %s\n", static_buf);
            break ;
        }
        static_buf = gnl_join_buffer(static_buf, buffer);
        printf("readings buf: %s\n", static_buf);
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

    if (!text)
        joined = (char *)malloc(sizeof(char) * (gnl_strlen(buffer) + 1));
    else
        joined = (char *)malloc(sizeof(char) * (gnl_strlen(text) + gnl_strlen(buffer) + 1));
    if (!joined)
        return (NULL);
    while (text[i++])
        joined[i] = text[i];
    while (buffer[j++])
        joined[i + j] = buffer[j];
    joined[i + j] = '\0';
    return (free(text), joined);
}

char    *get_next_line(int fd)
{
    static char     *buf;
    char            *output;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    printf("we have buffer in gnl\n");
    buf = reading(fd, buf);
    if (!buf)
        return (NULL);
    printf("%s\n", buf);
    if (gnl_strchr(buf, '\n') == -1)
    {
        printf("no newline\n");
        output = gnl_strcpy(buf, 0, gnl_strlen(buf));
        return (free(buf), output);
    }
    output = gnl_strcpy(buf, 0, gnl_strchr(buf, '\n'));
    if (!output)
        return (free(buf), NULL);
    printf("we have the output line: %s", output);
    buf = gnl_strcpy(buf, gnl_strchr(buf, '\n'), gnl_strlen(buf));
    if (!buf)
        return (free(output), NULL);
    return (output);
}
// #include <stdio.h>
// #include <fcntl.h>

// int main()
// {
//     char *a;
//     int fd = open("file.txt", O_RDONLY);
//    printf("fd: %d\n", fd);
//     a = get_next_line(fd);
//         printf("%s", a);
//     return (0);
// }