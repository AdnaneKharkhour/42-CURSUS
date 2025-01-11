/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:24:52 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/11 13:03:17 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	put_image(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coin_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'E' && count_coins(game) == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->open_exit_img, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->floor_img,
				x * TILE_SIZE, y * TILE_SIZE);
			put_image(game, x, y);
			if (game->map[y][x] == 'M')
				mlx_put_image_to_window(game->mlx, game->win, game->enemy_img,
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	display_score(game);
}
