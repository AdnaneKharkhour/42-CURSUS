#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int     ft_strchr(const char *s, int c);
char   *ft_substr(char *s, unsigned int start, size_t len);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
#endif