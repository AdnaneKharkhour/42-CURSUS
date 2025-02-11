/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:00:26 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/11 18:39:57 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	handle_child_process(int infile, int *fd, char *cmd, char **env)
{
	char	**cmd_args;
	char	*sh[3];

	close(fd[0]);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(infile);
	cmd_args = ft_split_pipex(cmd, ' ');
	if (cmd_args[0][0] == '.' && cmd_args[0][1] == '/')
	{
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

void	handle_second_child_process(int outfile, int *fd, char *cmd, char **env)
{
	char	**cmd_args;
	char	*sh[3];

	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[0]);
	close(outfile);
	cmd_args = ft_split_pipex(cmd, ' ');
	if (cmd_args[0][0] == '.' && cmd_args[0][1] == '/')
	{
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
	int	infile;
	int	outfile;

	if (argc != 5)
	{
		perror("ERROR\n");
		exit(EXIT_FAILURE);
	}
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (infile == -1 || outfile == -1)
	{
		perror("pipex");
		exit(EXIT_FAILURE);
	}
	create_pipes_and_forks(infile, outfile, argv, env);
	close(infile);
	close(outfile);
	return (0);
}
