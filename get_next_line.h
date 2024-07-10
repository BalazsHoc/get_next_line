#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef  BUFFER_SIZE
#  define  BUFFER_SIZE 12
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char    *get_next_line(int fd);
char    *gnl_join_buffer(char *text, char *buffer);
char    *reading(int fd, char *growing_text);

int     gnl_strlen(char *str);
int     gnl_strchr(char *str, int c);
char    *gnl_strlcpy(char *str, int len);
char    *gnl_fromnl(char *str);



#endif