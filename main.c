/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:47:47 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/15 17:25:08 by akharkho         ###   ########.fr       */
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

void ttyt()
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	int		width;
	int		height;
	t_game	game;

	atexit(ttyt);
	if (argc == 2)
	{
		width = 0;
		height = 0;
		map_check(argv[1]);
		game.mlx = mlx_init();
		game.map = load_map(argv[1]);
		count_map_width_height(&game, &width, &height);
		game.map_width = width;
		game.map_height = height;
		game.score = 0;
		game.moves = 0;
		game.player_x = 0;
		game.player_y = 0;
		game.direction = 'R';
		game.num_of_enemies = 0;
		game.collectibles_count = coins_counter(&game);
		player_position(&game);
		if (!bfs_check(&game))
		{
			ft_printf("Error: Map is not valid\n");
			exit(1);
		}
		init_enemy(&game);
		mlx_loop_hook(game.mlx, game_loop, &game);
		game.win = mlx_new_window(game.mlx, game.map_width * TILE_SIZE,
				game.map_height * TILE_SIZE, "pacman");
		loading_images(&game);
		render_map(&game);
		mlx_key_hook(game.win, key_hook, &game);
		mlx_loop(game.mlx);
		return (0);
	}
	system("leaks ./so_long");
	return (1);
}
