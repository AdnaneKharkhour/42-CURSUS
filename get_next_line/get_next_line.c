
#include "get_next_line.h"
#include <stdio.h> 
#include <stdlib.h> 

char *read_line(int fd)
{
	char *line;
	char *buffer;
	ssize_t bytes_read;

	line = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
		if (ft_strchr(buffer, '\n') >= 0)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (line);
}

char *extract_line(char *line)
{
	char *extracted_line;

	extracted_line = ft_substr(line, 0, ft_strchr(line, '\n') + 1);
	if (!extracted_line)
		return (NULL);
	return (extracted_line);
}

char	*get_next_line(int fd)
{
	static char	*rs;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free(rs);
		return (NULL);
	}
	rs = read_line(fd);
	printf("%s", rs);
	if (!rs)
		return (NULL);
	if (ft_strchr(rs, '\n') >= 0)
		rs = ft_substr(rs, 0, ft_strchr(rs, '\n') + 1);
	return (extract_line(rs));
}

int main()
{
    int fd = open("file.txt", O_CREAT | O_RDWR, 0777);
    char *line = get_next_line(fd);
     printf("%s", line);
    return 0;
}