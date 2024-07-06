#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef  BUFFER_SIZE
#  define  BUFFER_SIZE 12
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char    *get_next_line(int fd);
char    *reading(int fd, char *growing_text, int buffer_size);

void    ft_free(char *str);
int     gnl_strlen(char *str);
char    *gnl_join_buffer(char *text, char *buffer);
int     gnl_strchr(char *str, int c);
char    *gnl_strdup(char *str, int c);

#endif