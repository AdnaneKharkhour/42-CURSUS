/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:30:58 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/21 12:40:28 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	invalid_map_characters(void)
{
	ft_printf("Error:\nInvalid character in map\n");
	exit(EXIT_FAILURE);
}

bool	is_valid_move(t_game *game, int x, int y, bool **visited)
{
	return (x >= 0 && x < game->map_width && y >= 0 && y < game->map_height
		&& game->map[y][x] != '1' && !visited[y][x]);
}

void	initialise_variables(t_bfs_data *data)
{
	data->dx[0] = 1;
	data->dx[1] = -1;
	data->dx[2] = 0;
	data->dx[3] = 0;
	data->dy[0] = 0;
	data->dy[1] = 0;
	data->dy[2] = 1;
	data->dy[3] = -1;
	data->collectibles_found = 0;
	data->exit_found = 0;
}

void	initialise_visited(t_game *game, t_bfs_data *data)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		data->visited[i] = ft_calloc(game->map_width, sizeof(bool));
		if (!data->visited[i])
			exit(EXIT_FAILURE);
		i++;
	}
}

void	initialise_queue(t_game *game, t_bfs_data *data)
{
	data->queue[data->rear][0] = game->player_x;
	data->queue[data->rear++][1] = game->player_y;
	data->visited[game->player_y][game->player_x] = true;
}
