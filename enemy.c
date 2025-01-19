/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:02:47 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/19 15:39:51 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	add_enemy_position(t_game *game)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'M')
			{
				game->enemies[count].enemy_x = x;
				game->enemies[count].enemy_y = y;
				game->enemies[count].enemy_dir = 1;
				count++;
			}
			x++;
		}
		y++;
	}
}

void	init_enemy(t_game *game)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'M')
				count++;
			x++;
		}
		y++;
	}
	game->num_of_enemies = count;
	game->enemies = malloc(sizeof(t_enemy) * count);
	if (!game->enemies)
	{
		ft_printf("Error:\nFailed to allocate memory for enemies\n");
		exit(EXIT_FAILURE);
	}
	add_enemy_position(game);
}

void	first_check(t_game *game, int *i, int *x)
{
	*x = game->enemies[*i].enemy_x + game->enemies[*i].enemy_dir;
	if (game->map[game->enemies[*i].enemy_y][*x] == '1' ||
		game->map[game->enemies[*i].enemy_y][*x] == 'E' || x < 0 || 
		game->map[game->enemies[*i].enemy_y][*x] == 'C')
	{
		game->enemies[*i].enemy_dir *= -1;
		if (game->enemies[*i].enemy_dir > 0)
			game->enemy_img = game->enemy_img_right;
		else
			game->enemy_img = game->enemy_img_left;
	}
}

void	enemy_movement(t_game *game)
{
	int	i;
	int	x;

	i = 0;
	while (i < game->num_of_enemies)
	{
		first_check(game, &i, &x);
		if (game->map[game->enemies[i].enemy_y][x] == '0' ||
			game->map[game->enemies[i].enemy_y][x] == 'P')
		{
			if (game->map[game->enemies[i].enemy_y][x] == 'P')
			{
				ft_printf("GAME OVER\n");
				exit(0);
			}
			game->map[game->enemies[i].enemy_y][game->enemies[i].enemy_x] = '0';
			game->enemies[i].enemy_x = x;
			game->map[game->enemies[i].enemy_y][game->enemies[i].enemy_x] = 'M';
		}
		i++;
	}
}
