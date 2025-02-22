/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:55:48 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/22 19:29:34 by akharkho         ###   ########.fr       */
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

void	check_cmd_split(t_data *data, char *cmd)
{
	char	**cmd_args;
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
	exec_cmd(cmd_args[0], cmd_args, data->env);
	free_split(cmd_args);
	perror("execve");
	exit(EXIT_FAILURE);
}
