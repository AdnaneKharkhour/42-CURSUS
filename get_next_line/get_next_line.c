
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = (char *)malloc(1);
	if (!line)
	{
		free(buffer);
		return (NULL);
	}

	while (read(fd, buffer, BUFFER_SIZE))
	{
		line = ft_strjoin(line, buffer);
		if (!line)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}

	return (line);
}

int main (){
	int fd;
	fd = open("file.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s\n", line);
	return 0;
}