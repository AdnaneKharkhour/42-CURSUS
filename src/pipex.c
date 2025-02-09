/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:00:26 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/09 19:13:48 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../includes/pipex.h"

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
		int	file1;
		int	file2;

		file1 = open(argv[1], O_RDONLY);
		file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (file1 == -1 || file2 == -1)
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
			close(file2);
			dup2(file1, STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			close(file1);
			char **cmd1 = ft_split(argv[2], ' ');
			execve(cmd1[0], cmd1, env);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		int pid2 = fork();
		if (pid2 == -1)
			return (EXIT_FAILURE);
		if (pid2 == 0)
		{
			close(fd[1]);
			close(file1);
			dup2(fd[0], STDIN_FILENO);
			dup2(file2, STDOUT_FILENO);
			close(fd[0]);
			close(file2);
			char **cmd2 = ft_split(argv[3], ' ');
			execve(cmd2[0], cmd2, env);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		close(file1);
		close(file2);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	return (0);
}