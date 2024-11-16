
#include "get_next_line.h"
#include <stdio.h> 
#include <stdlib.h> 

static char *read_line(int fd, char *rs)
{
	// char *line;
	char buffer[BUFFER_SIZE + 1];
	ssize_t bytes_readed;

	// line = NULL;
	bytes_readed = read(fd, buffer, BUFFER_SIZE);
	while (bytes_readed > 0)
	{
		buffer[bytes_readed] = '\0';
		rs = ft_strjoin(rs, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_readed = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_readed < 0)
	{
		free(rs);
		rs = NULL;
		return (NULL);
	}
	return (rs);
}

static char *extract_line(char **rs)
{
	char *extracted_line;
	char *temp;

	if (ft_strchr(*rs, '\n') >= 0)
	{
		extracted_line = ft_substr(*rs, 0, ft_strchr(*rs, '\n') + 1);
		temp = ft_strdup(*rs + ft_strchr(*rs, '\n') + 1);
		// free(*rs);
		// *rs = temp;
	}
	else
	{
		extracted_line = ft_strdup(*rs);
		temp = NULL;
		// free(*rs);
		// *rs = NULL;
	}
	free(*rs);
	*rs = temp;
	return (extracted_line);
}

char	*get_next_line(int fd)
{
	static char	*rs;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free(rs);
		rs = NULL;
		return (NULL);
	}
	rs = read_line(fd, rs);
	if (!rs)
	{
		free(rs);
		rs = NULL;
		return (NULL);
	}
	return (extract_line(&rs));
}

int main()
{
    int fd = open("file.txt", O_CREAT | O_RDWR, 0777);
    char *line = get_next_line(fd);
    printf("%s", line);
	char *line1 = get_next_line(fd);
	printf("%s", line1);
    return 0;
}
