/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:48:50 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/17 18:00:02 by akharkho         ###   ########.fr       */
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
		int **fd, char *cmd, int i)
{
	char	**cmd_args;
	char	*sh[3];

	dup2(fd[i - 1][0], STDIN_FILENO);
	dup2(fd[i][1], STDOUT_FILENO);
	close_all_fd(fd, data->pipes_num);
	close(data->infile);
	close(data->outfile);
	cmd_args = ft_split_pipex(cmd, ' ');
	check_if_script(cmd_args, data, sh);
	free_split(cmd_args);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	handle_second_child_process(t_data *data,
		int **fd, char *cmd, int i)
{
	char	**cmd_args;
	char	*sh[3];

	dup2(fd[i - 1][0], STDIN_FILENO);
	dup2(data->outfile, STDOUT_FILENO);
	close_all_fd(fd, data->pipes_num);
	close(data->infile);
	close(data->outfile);
	cmd_args = ft_split_pipex(cmd, ' ');
	check_if_script(cmd_args, data, sh);
	free_split(cmd_args);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	handle_child_process(t_data *data, int **fd, char *cmd, int i)
{
	char	**cmd_args;
	char	*sh[3];

	dup2(data->infile, STDIN_FILENO);
	dup2(fd[i][1], STDOUT_FILENO);
	close_all_fd(fd, data->pipes_num);
	close(data->infile);
	close(data->outfile);
	cmd_args = ft_split_pipex(cmd, ' ');
	check_if_script(cmd_args, data, sh);
	free_split(cmd_args);
	perror("execve");
	exit(EXIT_FAILURE);
}
