#include <unistd.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 12

char    *get_next_line(int fd);
char    *reading(fd, BUFFER_SIZE);
size_t  gtl_strlen(char *str);
char    *gtl_join_buffer(char *text, char *buffer);

#endif