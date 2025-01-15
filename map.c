/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:45:32 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/15 16:31:07 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	count_lines(const char *file)
{
	int		fd;
	int		count;

	count = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd))
		count++;
	close(fd);
	return (count);
}

char	*remove_nl(char	*line)
{
	int	len;

	len = ft_strlen(line);
	if (line && len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

char	**load_map(const char *file)
{
	int		fd;
	int		i;
	int		num_lines;
	char	*line;
	char	**map;

	i = 0;
	num_lines = count_lines(file);
	map = malloc(sizeof(char *) * (num_lines + 1));
	if (!map)
		exit (EXIT_FAILURE);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		remove_nl(line);
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
