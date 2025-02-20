/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:48:50 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/20 15:55:44 by akharkho         ###   ########.fr       */
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
	dup2(fd[i - 1][0], STDIN_FILENO);
	dup2(data->outfile, STDOUT_FILENO);
	close_all_fd(fd, data->pipes_num);
	close(data->infile);
	close(data->outfile);
	check_cmd_split(data, cmd);
}

void	handle_child_process(t_data *data, int **fd, char *cmd, int i)
{
	dup2(data->infile, STDIN_FILENO);
	dup2(fd[i][1], STDOUT_FILENO);
	close_all_fd(fd, data->pipes_num);
	close(data->infile);
	close(data->outfile);
	check_cmd_split(data, cmd);
}
