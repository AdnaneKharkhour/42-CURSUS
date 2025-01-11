/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:47:47 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/11 14:06:12 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h>

void	key_handle(int keycode, int *x_mov, int *y_mov, t_game *game)
{
	if (keycode == 123)
	{
		(*x_mov)--;
		game->direction = 'L';
	}
	else if (keycode == 124)
	{
		(*x_mov)++;
		game->direction = 'R';
	}
	else if (keycode == 125)
	{
		(*y_mov)++;
		game->direction = 'D';
	}
	else if (keycode == 126)
	{
		(*y_mov)--;
		game->direction = 'U';
	}
	else if (keycode == 53)
		exit(0);
}

int	check_exit(int x_mov, int y_mov, t_game *game)
{
	int	coins_left;

	if (game->map[y_mov][x_mov] == 'E')
	{
		coins_left = count_coins(game);
		if (coins_left > 0)
		{
			render_map(game);
			display_score(game);
			return (1);
		}
		else
		{
			ft_printf("You win!\n");
			exit(0);
		}
	}
	return (0);
}

void	update_game(t_game	*game, int x_mov, int y_mov)
{
	if (game->map[y_mov][x_mov] == 'C')
	{
		game->score += 20;
		ft_printf("Score: %d\n", game->score);
	}
	if (game->map[y_mov][x_mov] == 'M')
	{
		ft_printf("GAME OVER");
		exit(0);
	}
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = x_mov;
	game->player_y = y_mov;
	game->map[game->player_y][game->player_x] = 'P';
	game->moves++;
	ft_printf("Moves count :%d\n", game->moves);
}

int	key_hook(int keycode, t_game *game)
{
	int	x_mov;
	int	y_mov;

	mlx_clear_window(game->mlx, game->win);
	x_mov = game->player_x;
	y_mov = game->player_y;
	key_handle(keycode, &x_mov, &y_mov, game);
	if (x_mov >= 0 && y_mov >= 0 && game->map[y_mov]
		&& game->map[y_mov][x_mov] != '1')
	{
		if (check_exit(x_mov, y_mov, game))
			return (0);
		update_game(game, x_mov, y_mov);
	}
	if (game->direction == 'U')
		game->player_img = game->player_img_up;
	else if (game->direction == 'D')
		game->player_img = game->player_img_down;
	else if (game->direction == 'L')
		game->player_img = game->player_img_left;
	else if (game->direction == 'R')
		game->player_img = game->player_img_right;
	render_map(game);
	display_score(game);
	return (0);
}

int	main(int argc, char **argv)
{
	int		map_width;
	int		map_height;
	t_game	game;

	if (argc == 2)
	{
		map_width = 0;
		map_height = 0;
		game.mlx = mlx_init();
		game.map = load_map(argv[1]);
		player_position(&game);
		while (game.map[0][map_width])
			map_width++;
		while (game.map[map_height])
			map_height++;
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
