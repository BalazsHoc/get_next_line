char    *reading(fd, BUFFER_SIZE)
{
    char    *buffer;
    char    *text;
    int     return_of_read;

    buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buffer)
        return (free(buffer), NULL);
    return_of_read = 1;
    while (return_of_read > 0)
    {
        return_of_read = read(fd, buffer, BUFFER_SIZE);
        if (return_of_read == -1)
            return (free(buffer), NULL);
        text = gtl_join_buffer(text, buffer);
        if (gtn_nl(text) == 1)
            break ;
    }
    free(buffer);
    return (text);
}

char    *get_next_line(int fd)
{
    static char     *rest;
    char            *output_line;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    rest = reading(fd, BUFFER_SIZE);
    if (!rest)
        return (free(rest), NULL);

    return (output_line);
}