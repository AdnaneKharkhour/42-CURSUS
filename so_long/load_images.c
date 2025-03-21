/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:58:30 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/21 12:32:42 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	player_images(t_game *game, int img_size)
{
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"textures/pacmanright.xpm", &img_size, &img_size);
}

void	other_images(t_game *game, int img_size)
{
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &img_size, &img_size);
	game->floor_img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	game->coin_img = mlx_xpm_file_to_image(game->mlx,
			"textures/coin.xpm", &img_size, &img_size);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"textures/door.xpm", &img_size, &img_size);
	game->open_exit_img = mlx_xpm_file_to_image(game->mlx,
			"textures/opendoor.xpm", &img_size, &img_size);
}

void	loading_images(t_game *game)
{
	int	img_size;

	img_size = TILE_SIZE;
	player_images(game, img_size);
	other_images(game, img_size);
	if (!game->player_img || !game->wall_img
		|| !game->floor_img || !game->coin_img || !game->exit_img
		|| !game->open_exit_img)
	{
		ft_printf("Error:\nFailed to load textures\n");
		exit(EXIT_FAILURE);
	}
}
