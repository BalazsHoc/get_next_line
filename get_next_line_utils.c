size_t  gtl_strlen(char *str)
{
    size_t  len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

char    *gtl_join_buffer(char *text, char *buffer)
{
    char    *joined;
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    joined = (char *)malloc(sizeof(char) * (gtl_strlen(text) + gtl_strlen(buffer) + 1));
    if (!joined)
        return (free(joined), NULL);
    
    while (text[i++])
        joined[i] = text[i];
    while (buffer[j++])
        joined[i + j] = buffer[j];
    return (free(text), free(buffer), joined);
}