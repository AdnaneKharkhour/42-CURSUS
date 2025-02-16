/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:48:50 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/16 19:02:06 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	check_permission(char **cmd)
{
	if (access(cmd[0], X_OK) == -1)
	{
		perror("pipex");
		exit(EXIT_FAILURE);
	}
}

void	check_if_script(char **cmd_args, t_data *data, char **sh)
{
	if (cmd_args[0][0] == '.' && cmd_args[0][1] == '/')
	{
		check_permission(cmd_args);
		sh[0] = "/bin/sh";
		sh[1] = cmd_args[0];
		sh[2] = NULL;
		exec_cmd(sh[0], sh, data->env);
	}
	else
		exec_cmd(cmd_args[0], cmd_args, data->env);
}

void	handle_middle_child_process(t_data *data,
		int *fd1, int *fd2, char *cmd)
{
	char	**cmd_args;
	char	*sh[3];

	dup2(fd1[0], STDIN_FILENO);
	dup2(fd2[1], STDOUT_FILENO);
	// close_fd(fd1[0], fd1[1], fd2[0], fd2[1]);
	close(fd1[0]);
	close(fd1[1]);
	close(fd2[0]);
	close(fd2[1]);
	close(data->infile);
	close(data->outfile);
	// print_open_fds();
	cmd_args = ft_split_pipex(cmd, ' ');
	check_if_script(cmd_args, data, sh);
	free_split(cmd_args);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	handle_second_child_process(t_data *data,
		int *fd, char *cmd)
{
	char	**cmd_args;
	char	*sh[3];

	dup2(fd[0], STDIN_FILENO);
	dup2(data->outfile, STDOUT_FILENO);
	// close_fd(data->infile, data->outfile, fd[0], fd[1]);
	close(data->infile);
	close(fd[0]);
	close(fd[1]);
	close(data->outfile);
	// print_open_fds();
	cmd_args = ft_split_pipex(cmd, ' ');
	check_if_script(cmd_args, data, sh);
	free_split(cmd_args);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	handle_child_process(t_data *data, int *fd, char *cmd)
{
	char	**cmd_args;
	char	*sh[3];

	dup2(data->infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	// close_fd(data->infile, data->outfile, fd[0], fd[1]);
	close(data->infile);
	close(fd[0]);
	close(fd[1]);
	close(data->outfile);
	// print_open_fds();
	cmd_args = ft_split_pipex(cmd, ' ');
	check_if_script(cmd_args, data, sh);
	free_split(cmd_args);
	perror("execve");
	exit(EXIT_FAILURE);
}
