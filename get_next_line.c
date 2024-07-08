
#include "get_next_line.h"

char    *reading(int fd, char *growing_text)
{
    char    *buffer;
    int     return_of_read;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    buffer[BUFFER_SIZE + 1] = '\0';
    return_of_read = 1;
    while (return_of_read > 0)
    {
        return_of_read = read(fd, buffer, BUFFER_SIZE);
        if (return_of_read == -1)
            return (free(buffer), free(growing_text), NULL);
        if (gnl_strchr(buffer, '\n') == 1)
        {
            growing_text = gnl_join_buffer(growing_text, buffer);
            break ;
        }
        growing_text = gnl_join_buffer(growing_text, buffer);
    }
    free(buffer);
    return (growing_text);
}

char    *get_next_line(int fd)
{
    static char     *rest;
    char            *output_line;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    rest = (char *)malloc(sizeof(char) * 1);
    if (!rest)
        return (NULL);
    rest = reading(fd, rest);
    if (!rest)
        return (NULL);
    if (gnl_strchr(rest, '\n') != 0)
    {
           output_line = gnl_strdup(rest, 1);
            if (!output_line)
                return (NULL);
    }
    else
    {
        output_line = gnl_strdup(rest, 2);
        if (!output_line)
            return (NULL);
        return (output_line);
    }
    return (output_line);
}
// #include <stdio.h>
// #include <fcntl.h>

// int main()
// {
//     char *a;
//     int fd = open("file.txt", O_RDWR);
   
//     a = get_next_line(fd);
//         printf("%s", a);
//     write(1, "h\n", 2);
// return (0);
// }