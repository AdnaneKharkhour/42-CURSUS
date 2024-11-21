/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:30:15 by akharkho          #+#    #+#             */
/*   Updated: 2024/11/17 11:30:15 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *rs)
{
	char	*buffer;
	ssize_t	bytes_readed;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(buffer), free(rs), rs = NULL, NULL);
	bytes_readed = read(fd, buffer, BUFFER_SIZE);
	while (bytes_readed > 0)
	{
		buffer[bytes_readed] = '\0';
		rs = ft_strjoin(rs, buffer);
		if (ft_strchr(buffer, '\n') != -1)
			break ;
		bytes_readed = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_readed < 0)
		return (free(buffer), free(rs), rs = NULL, NULL);
	return (free(buffer), buffer = NULL, rs);
}

static char	*extract_one_line(char **rs)
{
	char	*line;
	char	*temp;
	int		nl;

	nl = ft_strchr(*rs, '\n');
	if (nl >= 0)
	{
		line = ft_substr(*rs, 0, nl + 1);
		temp = ft_strdup(*rs + nl + 1);
		if (!temp)
			temp = ft_strdup("");
	}
	else
	{
		line = ft_strdup(*rs);
		temp = NULL;
	}
	free(*rs);
	*rs = temp;
	if (!line || (*rs && !**rs))
		return (free(*rs), *rs = NULL, line);
	return (line);
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
	if (!rs || *rs == '\0')
	{
		free(rs);
		rs = NULL;
		return (NULL);
	}
	return (extract_one_line(&rs));
}
