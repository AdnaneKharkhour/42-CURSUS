/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:00:26 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/13 16:34:51 by akharkho         ###   ########.fr       */
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

void	handle_child_process(t_data *data, int *fd, char *cmd, char **env)
{
	char	**cmd_args;
	char	*sh[3];

	dup2(data->infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(data->infile);
	close(fd[0]);
	close(data->outfile);
	cmd_args = ft_split_pipex(cmd, ' ');
	if (cmd_args[0][0] == '.' && cmd_args[0][1] == '/')
	{
		check_permission(cmd_args);
		sh[0] = "/bin/sh";
		sh[1] = cmd_args[0];
		sh[2] = NULL;
		exec_cmd(sh[0], sh, env);
	}
	else
		exec_cmd(cmd_args[0], cmd_args, env);
	free_split(cmd_args);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	handle_second_child_process(t_data *data,
		int *fd, char *cmd, char **env)
{
	char	**cmd_args;
	char	*sh[3];

	dup2(fd[0], STDIN_FILENO);
	dup2(data->outfile, STDOUT_FILENO);
	close(fd[0]);
	close(data->outfile);
	close(fd[1]);
	close(data->infile);
	cmd_args = ft_split_pipex(cmd, ' ');
	if (cmd_args[0][0] == '.' && cmd_args[0][1] == '/')
	{
		check_permission(cmd_args);
		sh[0] = "/bin/sh";
		sh[1] = cmd_args[0];
		sh[2] = NULL;
		exec_cmd(sh[0], sh, env);
		perror("execve");
	}
	else
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
		write(2, "ERROR:\nthere should be 4 args\n", 30);
		exit(EXIT_FAILURE);
	}
	data.infile = open(argv[1], O_RDONLY);
	data.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data.infile == -1 || data.outfile == -1)
	{
		perror("pipex");
		exit(EXIT_FAILURE);
	}
	create_pipes_and_forks(&data, argv, env);
	close(data.infile);
	close(data.outfile);
	return (0);
}
