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
	char	*temp;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(rs), rs = NULL, NULL);
	while (ft_strchr(rs, '\n') == -1)
	{
		bytes_readed = read(fd, buffer, BUFFER_SIZE);
		if (bytes_readed <= 0)
			return (free(buffer), rs);
		buffer[bytes_readed] = '\0';
		temp = ft_strjoin(rs, buffer);
		free(rs);
		rs = temp;
		if (!rs)
			return (free(buffer), NULL);
	}
	return (free(buffer), rs);
}

static char	*extract_one_line(char **rs)
{
	char	*line;
	char	*temp;
	int		nl;

	nl = ft_strchr(*rs, '\n');
	if (nl == -1)
	{
		nl = 0;
		while (*rs[nl] != '\0')
			nl++;
	}
	line = ft_substr(*rs, 0, nl + 1);
	temp = ft_strdup(*rs + nl + 1);
	free(*rs);
	*rs = temp;
	if (!line || (*rs && !**rs))
		return (free(*rs), *rs = NULL, line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rs;
	char		*rst;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(rs), rs = NULL, NULL);
	if (!rs)
		rs = ft_strdup("");
	if (!rs)
		return (NULL);
	rs = read_line(fd, rs);
	if (!rs || *rs == '\0')
		return (free (rs), rs = NULL, NULL);
	if (ft_strchr(rs, '\n') != -1)
		rst = extract_one_line(&rs);
	else
	{
		rst = ft_strdup(rs);
		free(rs);
		rs = NULL;
	}
	return (rst);
}
