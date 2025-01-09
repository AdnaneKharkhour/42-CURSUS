/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:47:47 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/09 19:21:59 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h>

// void	loading_images(t_game *game)
// {
// 	int	img_size;

// 	img_size = TILE_SIZE;
// 	game->player_img = mlx_xpm_file_to_image(game->mlx,
// 			"textures/pacmanright.xpm", &img_size, &img_size);
// 	game->player_img_right = mlx_xpm_file_to_image(game->mlx,
// 			"textures/pacmanright.xpm", &img_size, &img_size);
// 	game->player_img_left = mlx_xpm_file_to_image(game->mlx,
// 			"textures/pacmanleft.xpm", &img_size, &img_size);
// 	game->player_img_up = mlx_xpm_file_to_image(game->mlx,
// 			"textures/pacmanup.xpm", &img_size, &img_size);
// 	game->player_img_down = mlx_xpm_file_to_image(game->mlx,
// 			"textures/pacmandown.xpm", &img_size, &img_size);
// 	game->wall_img = mlx_xpm_file_to_image(game->mlx,
// 			"textures/wall.xpm", &img_size, &img_size);
// 	// game->floor_img = mlx_xpm_file_to_image(game->mlx,"textures/floor.xpm", &img_size, &img_size);
// 	game->floor_img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
// 	game->coin_img = mlx_xpm_file_to_image(game->mlx,
// 			"textures/coin.xpm", &img_size, &img_size);
// 	game->exit_img = mlx_xpm_file_to_image(game->mlx,
// 			"textures/door.xpm", &img_size, &img_size);
// 	game->open_exit_img = mlx_xpm_file_to_image(game->mlx,
// 			"textures/opendoor.xpm", &img_size, &img_size);
// 	game->enemy_img = mlx_xpm_file_to_image(game->mlx,
// 			"textures/ghost.xpm", &img_size, &img_size);
// 	if (!game->player_img_right || !game->wall_img || !game->floor_img 
// 		|| !game->coin_img || !game->exit_img || !game->enemy_img || !game->player_img_left || !game->player_img_up || !game->player_img_down || !game->open_exit_img)
// 	{
// 		fprintf(stderr, "Error: Failed to load textures\n");
// 		exit(1);
// 	}
// }

// int	count_coins(t_game *game)
// {
// 	int	coins;
// 	int	i;
// 	int	j;

// 	i = 0;
// 	coins = 0;
// 	while(game->map[i])
// 	{
// 		j = 0;
// 		while (game->map[i][j])
// 		{
// 			if (game->map[i][j] == 'C')
// 				coins++;
// 			j++;
// 		}
// 		i++;	
// 	}
// 	return (coins);
// }

// void	render_map(t_game *game)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (game->map[y])
// 	{
// 		x = 0;
// 		while (game->map[y][x])
// 		{
// 			mlx_put_image_to_window(game->mlx, game->win, game->floor_img,
// 				x * TILE_SIZE, y * TILE_SIZE);
// 			if (game->map[y][x] == '1')
// 			{
// 				mlx_put_image_to_window(game->mlx, game->win, game->wall_img,
// 					x * TILE_SIZE, y * TILE_SIZE);
// 			}
// 			else if (game->map[y][x] == 'P')
// 			{
// 				mlx_put_image_to_window(game->mlx, game->win, game->player_img,
// 					x * TILE_SIZE, y * TILE_SIZE);
// 			}
// 			else if (game->map[y][x] == 'C')
// 			{
// 				mlx_put_image_to_window(game->mlx, game->win, game->coin_img,
// 					x * TILE_SIZE, y * TILE_SIZE);
// 			}
// 			else if (game->map[y][x] == 'E' && count_coins(game) == 0)
// 			{
// 				mlx_put_image_to_window(game->mlx, game->win, game->open_exit_img,
// 					x * TILE_SIZE, y * TILE_SIZE);
// 			}
// 			else if (game->map[y][x] == 'E')
// 			{
// 				mlx_put_image_to_window(game->mlx, game->win, game->exit_img,
// 					x * TILE_SIZE, y * TILE_SIZE);
// 			}
// 			else if (game->map[y][x] == 'M')
// 			{
// 				mlx_put_image_to_window(game->mlx, game->win, game->enemy_img,
// 					x * TILE_SIZE, y * TILE_SIZE);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// char	*ft_itoa(int n)
// {
// 	char	*str;
// 	int		len;
// 	int		nb;

// 	nb = n;
// 	len = 1;
// 	while (nb /= 10)
// 		len++;
// 	str = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	str[len] = '\0';
// 	while (len--)
// 	{
// 		str[len] = n % 10 + '0';
// 		n /= 10;
// 	}
// 	return (str);
// }

// void	display_score(t_game *game)
// {
// 	char	*score;
// 	char	*moves;

// 	score = ft_itoa(game->score);
// 	moves = ft_itoa(game->moves);
// 	mlx_string_put(game->mlx, game->win, 10, 10, 0x00FFFFFF, "Score: ");
// 	mlx_string_put(game->mlx, game->win, 70, 10, 0x00FFFFFF, score);
// 	mlx_string_put(game->mlx, game->win, 10, 30, 0x00FFFFFF, "Moves: ");
// 	mlx_string_put(game->mlx, game->win, 70, 30, 0x00FFFFFF, moves);
// }


void	key_handle(int	keycode, int *x_mov, int *y_mov, t_game *game)
{
	if (keycode == 123)//left
	{
		(*x_mov)--;
		game->direction = 'L';
	}
	else if (keycode == 124)//right
		{
			(*x_mov)++;
			game->direction = 'R';
		}
	else if (keycode == 125)//down
		{
			(*y_mov)++;
			game->direction = 'D';
		}
	else if (keycode == 126)//up
		{
			(*y_mov)--;
			game->direction = 'U';
		}
	else if (keycode == 53)//esc
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
				printf("You win!\n");
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
		printf("Score: %d\n", game->score);
	}
	if (game->map[y_mov][x_mov] == 'M')
	{
		printf("GAME OVER");
		exit(0);
	}
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = x_mov;
	game->player_y = y_mov;
	game->map[game->player_y][game->player_x] = 'P';
	game->moves++;
	printf("Moves count :%d\n", game->moves);
}

int	key_hook(int keycode,t_game *game)
{
	int	x_mov;
	int y_mov;

	mlx_clear_window(game->mlx, game->win);
	x_mov = game->player_x;
	y_mov = game->player_y;
	key_handle(keycode, &x_mov, &y_mov, game);
	if (x_mov >= 0 && y_mov >= 0 && game->map[y_mov] && game->map[y_mov][x_mov] != '1')
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

int main(int argc, char **argv)
{
	int map_width;
	int map_height;
	t_game game;


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
		game.win = mlx_new_window(game.mlx, map_width * TILE_SIZE,map_height * TILE_SIZE, "pacman");
		loading_images(&game);
		render_map(&game);
		mlx_key_hook(game.win, key_hook, &game);
		mlx_loop(game.mlx);
		return (0);
	}
	return (1);
}
