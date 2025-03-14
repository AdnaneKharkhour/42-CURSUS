/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:00:26 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/11 06:41:02 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	handle_here_doc(char *limiter, t_data *data)
{
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		exit_error("pipe");
	write(1, "pipe heredoc>", 13);
	line = get_next_line(0);
	while (line)
	{
		if (!ft_strncmp(line, limiter, ft_strlen(limiter)) 
			&& (ft_strlen(line) - 1) == ft_strlen(limiter))
			break ;
		write(fd[1], line, ft_strlen(line));
		free(line);
		write(1, "pipe heredoc>", 13);
		line = get_next_line(0);
	}
	free(line);
	close(fd[1]);
	data->infile = fd[0];
}

static void	handle_arguments(int argc, char **argv, t_data *data)
{
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		data->here_doc = 1;
		if (argc < 6)
			exit_error("./pipex here_doc LIMITER cmd1 cmd2 ... cmdn outfile");
		handle_here_doc(argv[2], data);
	}
	else
		data->here_doc = 0;
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc < 5)
	{
		write(2, "ERROR:\n ./pipex infile cmd1 cmd2 ... cmdn outfile\n", 50);
		exit(EXIT_FAILURE);
	}
	data.env = env;
	data.argc = argc;
	data.argv = argv;
	handle_arguments(argc, argv, &data);
	return (create_pipes_and_forks(argc, &data, argv));
}
