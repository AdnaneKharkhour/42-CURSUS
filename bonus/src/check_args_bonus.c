/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:55:48 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/20 15:56:06 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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

void	check_cmd_split(t_data *data, char *cmd)
{
	char	**cmd_args;
	char	*sh[3];
	int		j;

	j = 0;
	while (cmd[j] == ' ')
		j++;
	if (!cmd || cmd[j] == '\0')
	{
		write(2, "pipex: permission denied\n", 26);
		exit(EXIT_FAILURE);
	}
	cmd_args = ft_split_pipex(cmd, ' ');
	if (!cmd_args)
		perror("split");
	check_if_script(cmd_args, data, sh);
	free_split(cmd_args);
	perror("execve");
	exit(EXIT_FAILURE);
}
