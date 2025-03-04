/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:48:50 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/04 16:07:00 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	handle_middle_child_process(t_data *data,
		int **fd, char *cmd, int i)
{
	dup2(fd[i - 1][0], STDIN_FILENO);
	dup2(fd[i][1], STDOUT_FILENO);
	close_all_fd(fd, data->pipes_num);
	close(data->infile);
	close(data->outfile);
	check_cmd_split(data, cmd);
}

void	handle_second_child_process(t_data *data,
		int **fd, char *cmd, int i)
{
	if (data->here_doc == 1)
		data->outfile = open(data->argv[data->argc - 1], O_WRONLY
				| O_CREAT | O_APPEND, 0664);
	else
		data->outfile = open(data->argv[data->argc - 1], O_WRONLY
				| O_CREAT | O_TRUNC, 0644);
	if (data->outfile == -1)
	{
		close_all_fd(fd, data->pipes_num);
		perror("pipex");
		exit(EXIT_FAILURE);
	}
	dup2(fd[i - 1][0], STDIN_FILENO);
	dup2(data->outfile, STDOUT_FILENO);
	close_all_fd(fd, data->pipes_num);
	close(data->outfile);
	check_cmd_split(data, cmd);
}

void	handle_child_process(t_data *data, int **fd, char *cmd, int i)
{
	if (data->here_doc == 0)
		data->infile = open(data->argv[1], O_RDONLY);
	if (data->infile == -1)
	{
		close_all_fd(fd, data->pipes_num);
		perror("pipex");
		exit(EXIT_FAILURE);
	}
	dup2(data->infile, STDIN_FILENO);
	dup2(fd[i][1], STDOUT_FILENO);
	close_all_fd(fd, data->pipes_num);
	close(data->infile);
	check_cmd_split(data, cmd);
}
