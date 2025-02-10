/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:00:26 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/10 17:51:19 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../includes/pipex.h"

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**get_path(char **env)
{
	int		i;
	char	**path;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
	{
		printf("PATH NOT FOUND");
		exit(EXIT_FAILURE);
	}
	path = ft_split(env[i] + 5, ':');
	if (!path)
	{
		printf("ERROR PATH");
		exit(EXIT_FAILURE);
	}
	return (path);
}

void	exec_cmd(char *cmd, char **argv, char **env)
{
	char	**path;
	char	*tmp;
	char	*tmp2;
	int		i;

	if (access(cmd, X_OK) == 0)
		execve(cmd, argv, env);
	path = get_path(env);
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		free(tmp);
		printf("Running command: %s\n", cmd);
		for (int i = 0; argv[i] != NULL; i++) {
			printf("Argument %d: %s\n", i, argv[i]);
		}

		if (access(tmp2, X_OK) == 0)
		{
			execve(tmp2, argv, env);
			free(tmp2);
		}
		free(tmp2);
		i++;
	}
	free_split(path);
	printf("ERROR COMMAND NOT FOUND");
	exit(EXIT_FAILURE);
}

int	main(int argc, char ** argv, char **env)
{
	if (argc != 5)
	{
		printf("wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		int fd[2];
		int	infile;
		int	outfile;

		infile = open(argv[1], O_RDONLY);
		outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (infile == -1 || outfile == -1)
		{
			printf("error with files\n");
			exit(EXIT_FAILURE);
		}
		if (pipe(fd) == -1)
		{
			printf("error with pipe\n");
			exit(EXIT_FAILURE);
		}
		int pid1 = fork();
		if (pid1 == -1)
			return (EXIT_FAILURE);
		if (pid1 == 0)
		{
			close(fd[0]);
			close(outfile);
			dup2(infile, STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			close(infile);
			char **cmd1 = ft_split(argv[2], ' ');
			exec_cmd(cmd1[0], cmd1, env);
			free_split(cmd1);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		int pid2 = fork();
		if (pid2 == -1)
			return (EXIT_FAILURE);
		if (pid2 == 0)
		{
			close(fd[1]);
			close(infile);
			dup2(fd[0], STDIN_FILENO);
			dup2(outfile, STDOUT_FILENO);
			close(fd[0]);
			close(outfile);
			char **cmd2 = ft_split(argv[3], ' ');
			exec_cmd(cmd2[0], cmd2, env);
			free_split(cmd2);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		close(infile);
		close(outfile);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	return (0);
}
