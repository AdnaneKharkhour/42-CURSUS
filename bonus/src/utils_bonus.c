/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:55:36 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/20 15:13:30 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	exit_error_and_free(int **fd, int i, const char *error)
{
	if (fd)
	{
		while (i >= 0)
		{
			close(fd[i][0]);
			close(fd[i][1]);
			free(fd[i]);
			i--;
		}
		free(fd);
	}
	exit_error(error);
}

void	exit_error(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	close_all_fd(int **fd, int pipes_num)
{
	int	i;

	i = 0;
	while (i < pipes_num)
	{
		if (fd[i] != NULL)
		{
			close(fd[i][0]);
			close(fd[i][1]);
			free(fd[i]);
			i++;
		}
	}
	free(fd);
}

char	**get_path(char **env)
{
	int		i;
	char	**path;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
	{
		perror("PATH");
		exit(EXIT_FAILURE);
	}
	path = ft_split_pipex(env[i] + 5, ':');
	if (!path)
	{
		perror("split");
		exit(EXIT_FAILURE);
	}
	return (path);
}
