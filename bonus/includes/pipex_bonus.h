/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:07:50 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/19 13:50:27 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "get_next_line_bonus.h"
# include "libft_bonus.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_pipex_data
{
	int		infile;
	int		outfile;
	int		pipes_num;
	int		here_doc;
	char	**env;
}t_data;

//ft_split_pipex_bonus.c
char	**split_string(const char *s, char c, char **string);
char	**ft_split_pipex(char const *s, char c);
//ft_split_pipex_utils_bonus.c
void	ft_quotes(const char *str, int *in_quote);
char	**free_string(char **string, int i);
//pipex_utils_bonus.c
void	exec_cmd_from_path(char **path, char *cmd, char **argv, char **env);
void	exec_cmd(char *cmd, char **argv, char **env);
void	handle_cmds(t_data *data, int **fd, int total_cmds, char **argv);
void	create_pipes_and_forks(int argc, t_data *data, char **argv);
//utils_bonus.c
void	free_split(char **str);
void	exit_error_and_free(int **fd, int i, const char *error);
void	exit_error(const char *str);
void	close_all_fd(int **fd, int total_cmds);
char	**get_path(char **env);
//process_bonus.c
void	check_permission(char **cmd);
void	check_if_script(char **cmd_args, t_data *data, char **sh);
void	handle_middle_child_process(t_data *data,
			int **fd, char *cmd, int i);
void	handle_second_child_process(t_data *data,
			int **fd, char *cmd, int i);
void	handle_child_process(t_data *data, int **fd, char *cmd, int i);
//main_bonus.c

#endif