/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:52:43 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/15 16:42:51 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	explore_adjacent_cells(t_game *game, t_bfs_data *data, int x, int y)
{
	int	i;
	int	new_x;
	int	new_y;

	i = 0;
	while (i < 4)
	{
		new_x = x + data->dx[i];
		new_y = y + data->dy[i];
		if (is_valid_move(game, new_x, new_y, data->visited))
		{
			data->queue[data->rear][0] = new_x;
			data->queue[data->rear++][1] = new_y;
			data->visited[new_y][new_x] = true;
		}
		i++;
	}
}

void	free_visited(t_game *game, t_bfs_data *data)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		free(data->visited[i]);
		i++;
	}
	free(data->visited);
}

void	count_collectibles_and_exits(t_game *game, int x,
		int y, t_bfs_data *data)
{
	if (game->map[y][x] == 'C')
		data->collectibles_found++;
	if (game->map[y][x] == 'E')
		data->exit_found++;
}

void	bfs_loop(t_game *game, t_bfs_data *data)
{
	int	x;
	int	y;

	while (data->front < data->rear)
	{
		x = data->queue[data->front][0];
		y = data->queue[data->front++][1];
		count_collectibles_and_exits(game, x, y, data);
		explore_adjacent_cells(game, data, x, y);
	}
}

bool	bfs_check(t_game *game)
{
	t_bfs_data	data;

	data.front = 0;
	data.rear = 0;
	initialise_variables(&data);
	data.visited = malloc(game->map_height * sizeof(bool *));
	if (!data.visited)
		exit(EXIT_FAILURE);
	initialise_visited(game, &data);
	data.queue = malloc(game->map_height * game->map_width * sizeof(int [2]));
	if (!data.queue)
		exit(EXIT_FAILURE);
	initialise_queue(game, &data);
	bfs_loop(game, &data);
	free(data.queue);
	free_visited(game, &data);
	return (data.collectibles_found == game->collectibles_count
		&& data.exit_found > 0);
}
