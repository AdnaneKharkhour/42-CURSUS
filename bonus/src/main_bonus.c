/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:00:26 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/15 18:00:11 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc < 5)
	{
		write(2, "ERROR:\nthere should be 4 args\n", 30);
		exit(EXIT_FAILURE);
	}
	data.env = env;
	data.infile = open(argv[1], O_RDONLY);
	data.outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data.infile == -1 || data.outfile == -1)
	{
		perror("pipex");
		exit(EXIT_FAILURE);
	}
	create_pipes_and_forks(argc, &data, argv);
	close(data.infile);
	close(data.outfile);
	return (0);
}
