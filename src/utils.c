/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:55:36 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/01 18:43:00 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	helper(int *fd, int *pid2)
{
	int	status;

	close(fd[0]);
	close(fd[1]);
	waitpid(*pid2, &status, 0);
	wait(NULL);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
