
#include "get_next_line.h"

char    *reading(int fd, char *growing_text, int buffer_size)
{
    char    *buffer;
    int     return_of_read;

    buffer = (char *)malloc(sizeof(char) * buffer_size + 1);
    if (!buffer)
        return (ft_free(buffer), ft_free(growing_text), NULL);
    buffer[buffer_size + 1] = '\0';
    return_of_read = 1;
    while (return_of_read > 0)
    {
        return_of_read = read(fd, buffer, buffer_size);
        if (return_of_read == -1)
            return (ft_free(buffer), ft_free(growing_text), NULL);
        if (gnl_strchr(buffer, '\n') != 0)
        {
            growing_text = gnl_join_buffer(growing_text, buffer);
            break ;
        }
        growing_text = gnl_join_buffer(growing_text, buffer);
    }
    ft_free(buffer);
    return (growing_text);
}

char    *get_next_line(int fd)
{
    static char     *rest;
    char            *output_line;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    rest = reading(fd, rest, BUFFER_SIZE);
    if (!rest)
        return (ft_free(rest), NULL);
    if (gnl_strchr(rest, '\n') != 0)
    {
           output_line = gnl_strdup(rest, 1);
            if (!output_line)
                return (ft_free(output_line), ft_free(rest), NULL);
    }
    else
    {
        output_line = gnl_strdup(rest, 2);
        if (!output_line)
            return (ft_free(output_line), ft_free(rest), NULL);
        return (ft_free(rest), output_line);
    }
    return (output_line);
}
// #include <stdio.h>

// int main()
// {
//     int fd = open("file.txt", O_RDWR);
//     while (1)
//     {
//         printf("%s", get_next_line(fd));
//     }
// return (0);
// }