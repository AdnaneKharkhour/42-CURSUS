/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:47:47 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/13 18:56:47 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	game_loop(t_game *game)
{
	static int	frame = 0;

	if (frame % 10 == 0)
		enemy_movement(game);
	render_map(game);
	display_score(game);
	frame++;
	return (0);
}

int	main(int argc, char **argv)
{
	int		map_width;
	int		map_height;
	t_game	game;

	if (argc == 2)
	{
		map_check(argv[1]);
		map_width = 0;
		map_height = 0;
		game.mlx = mlx_init();
		game.map = load_map(argv[1]);
		if(!bfs_check(&game, map_width, map_height))
		{
			ft_printf("Error: Map is not valid\n");
			exit(1);
		}
		player_position(&game);
		init_enemy(&game);
		mlx_loop_hook(game.mlx, game_loop, &game);
		count_map_width_height(&game, &map_width, &map_height);
		game.win = mlx_new_window(game.mlx, map_width * TILE_SIZE,
				map_height * TILE_SIZE, "pacman");
		loading_images(&game);
		render_map(&game);
		mlx_key_hook(game.win, key_hook, &game);
		mlx_loop(game.mlx);
		return (0);
	}
	return (1);
}
