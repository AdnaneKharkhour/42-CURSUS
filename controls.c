/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:32:58 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/13 18:19:02 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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
		coins_left = coins_counter(game);
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
