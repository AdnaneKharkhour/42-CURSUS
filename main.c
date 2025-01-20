/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:47:47 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/20 13:54:35 by akharkho         ###   ########.fr       */
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

// void	ttyt(void)
// {
// 	system("leaks -q so_long");
// }

void	initialise_struct(t_game *game)
{
	game->map_width = 0;
	game->map_height = 0;
	game->score = 0;
	game->moves = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->direction = 'R';
	game->num_of_enemies = 0;
	game->collectibles_count = coins_counter(game);
}

void	check_if_playable(t_game *game, char **argv)
{
	map_check(argv[1]);
	game->mlx = mlx_init();
	game->map = load_map(argv[1]);
	initialise_struct(game);
	count_map_width_height(game, &game->map_width, &game->map_height);
	player_position(game);
	if (!bfs_check(game))
	{
		ft_printf("Error:\nMap is not valid\n");
		free_map(game->map);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		check_if_playable(&game, argv);
		init_enemy(&game);
		mlx_loop_hook(game.mlx, game_loop, &game);
		game.win = mlx_new_window(game.mlx, game.map_width * TILE_SIZE,
				game.map_height * TILE_SIZE, "pacman");
		loading_images(&game);
		render_map(&game);
		mlx_key_hook(game.win, key_hook, &game);
		mlx_loop(game.mlx);
		free_map(game.map);
		return (EXIT_SUCCESS);
	}
	ft_printf("Error:\narguments error\n");
	return (EXIT_FAILURE);
}
