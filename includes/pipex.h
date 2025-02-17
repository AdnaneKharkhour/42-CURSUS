/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:07:50 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/17 16:43:31 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../utils/libft_pipex/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_pipex_data
{
	int	infile;
	int	outfile;
}t_data;

//ft_split_pipex.c
void	ft_quotes(const char *str, int *in_quote);
char	**free_string(char **string, int i);
char	**ft_split_pipex(char const *s, char c);
//pipex_utils.c
char	**get_path(char **env);
void	exec_cmd_from_path(char **path, char *cmd, char **argv, char **env);
void	exec_cmd(char *cmd, char **argv, char **env);
void	create_pipes_and_forks(t_data *data, char **argv, char **env);
//utils.c
void	free_split(char **str);
//main.c
void	handle_child_process(t_data *data, int *fd, char *cmd, char **env);
void	handle_second_child_process(t_data *data,
			int *fd, char *cmd, char **env);

#endif