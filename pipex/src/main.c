/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:00:26 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/11 06:39:55 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_permission(char **cmd)
{
	if (access(cmd[0], X_OK) == -1)
	{
		perror("pipex");
		exit(EXIT_FAILURE);
	}
}

void	check_cmd(char *cmd)
{
	int		j;

	j = 0;
	while (cmd[j] == ' ')
		j++;
	if (!cmd || cmd[j] == '\0')
	{
		write(2, "pipex: permission denied\n", 26);
		close(0);
		close(1);
		exit(EXIT_FAILURE);
	}
}

void	handle_child_process(t_data *data, int *fd, char *cmd, char **env)
{
	char	**cmd_args;

	data->infile = open(data->argv[1], O_RDONLY);
	if (data->infile == -1)
	{
		perror("pipex");
		close(fd[1]);
		close(fd[0]);
		exit(1);
	}
	dup2(data->infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(data->infile);
	check_cmd(cmd);
	cmd_args = ft_split_pipex(cmd, ' ');
	exec_cmd(cmd_args[0], cmd_args, env);
	free_split(cmd_args);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	handle_second_child_process(t_data *data,
		int *fd, char *cmd, char **env)
{
	char	**cmd_args;

	data->outfile = open(data->argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile == -1)
	{
		perror("pipex");
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(data->outfile, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(data->outfile);
	check_cmd(cmd);
	cmd_args = ft_split_pipex(cmd, ' ');
	exec_cmd(cmd_args[0], cmd_args, env);
	free_split(cmd_args);
	perror("execve");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc != 5)
	{
		write(2, "ERROR:\n ./pipex infile cmd1 cmd2 outfile\n", 41);
		exit(EXIT_FAILURE);
	}
	data.argv = argv;
	return (create_pipes_and_forks(&data, argv, env));
}
