/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:56:39 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/27 14:04:37 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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
	exit(EXIT_FAILURE);
}

void	handle_cmds(t_data *data, int **fd, int total_cmds, char **argv)
{
	int		i;
	int		pid;

	i = 0;
	while (i < total_cmds)
	{
		pid = fork();
		if (pid == -1)
			exit_error("fork");
		if (pid == 0)
		{
			if (i == 0)
				handle_child_process(data, fd, argv[i + 2], i);
			else if (i == total_cmds - 1)
				handle_second_child_process(data, fd,
					argv[i + 2], i);
			else
				handle_middle_child_process(data,
					fd, argv[i + 2], i);
		}
		i++;
	}
}

static void	create_pipes(t_data *data, int **fd)
{
	int	i;

	i = 0;
	while (i < data->pipes_num)
	{
		fd[i] = malloc(sizeof(int) * 2);
		if (!fd[i])
			exit_error_and_free(fd, i, "fd malloc");
		if (pipe(fd[i]) == -1)
			exit_error_and_free(fd, i, "pipe");
		i++;
	}
}

void	create_pipes_and_forks(int argc, t_data *data, char **argv)
{
	int	**fd;
	int	total_cmds;

	total_cmds = argc - 3;
	if (data->here_doc == 1)
	{
		total_cmds = argc - 4;
		argv += 1;
	}
	data->pipes_num = total_cmds - 1;
	fd = malloc(sizeof(int *) * data->pipes_num);
	if (!fd)
		exit_error("fd malloc");
	create_pipes(data, fd);
	handle_cmds(data, fd, total_cmds, argv);
	close_all_fd(fd, data->pipes_num);
	close(data->infile);
	close(data->outfile);
	while (--total_cmds >= 0)
		wait(NULL);
}
