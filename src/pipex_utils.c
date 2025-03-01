/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:56:39 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/01 18:42:19 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

void	exec_cmd_from_path(char **path, char *cmd, char **argv, char **env)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(tmp2, X_OK) == 0)
		{
			execve(tmp2, argv, env);
			free(tmp2);
			exit(EXIT_FAILURE);
		}
		if (tmp2)
			free(tmp2);
		i++;
	}
}

void	exit_error(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	exec_cmd(char *cmd, char **argv, char **env)
{
	char	**path;

	if (access(cmd, X_OK) == 0)
	{
		execve(cmd, argv, env);
		exit_error("execve");
	}
	path = get_path(env);
	exec_cmd_from_path(path, cmd, argv, env);
	free_split(path);
	free_split(argv);
	write(2, "pipex: command not found:", 25);
	exit(127);
}

int	create_pipes_and_forks(t_data *data, char **argv, char **env)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) == -1)
	{
		perror("pipex: Pipe creation failed");
		exit(EXIT_FAILURE);
	}
	pid1 = fork();
	if (pid1 == -1)
		exit_error("fork");
	if (pid1 == 0)
		handle_child_process(data, fd, argv[2], env);
	pid2 = fork();
	if (pid2 == -1)
		exit_error("fork");
	if (pid2 == 0)
		handle_second_child_process(data, fd, argv[3], env);
	return (helper(fd, &pid2));
}
