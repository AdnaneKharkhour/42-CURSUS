#include "game.h"
#include <stdio.h>

void	loading_images(t_game *game)
{
	int	img_size;

	img_size = TILE_SIZE;
	game->player_img = mlx_xpm_file_to_image(game->mlx, "textures/pacman.xpm", &img_size, &img_size);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &img_size, &img_size);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &img_size, &img_size);
	game->coin_img = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm", &img_size, &img_size);
	if(!game->player_img || !game->wall_img || !game->floor_img || !game->coin_img)
	{
		fprintf(stderr, "Error: Failed to load textures\n");
		exit(1);
	}
}

void render_map(t_game *game) {
    int y;
	int	x;

    y = 0;
    while (game->map[y]) {
        x = 0;
        while (game->map[y][x]) {
            mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x * TILE_SIZE, y * TILE_SIZE);
            if (game->map[y][x] == '1') {
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
            } else if (game->map[y][x] == 'P') {
                mlx_put_image_to_window(game->mlx, game->win, game->player_img, x * TILE_SIZE, y * TILE_SIZE);
            } else if (game->map[y][x] == 'C') {
				mlx_put_image_to_window(game->mlx, game->win, game->coin_img, x * TILE_SIZE, y* TILE_SIZE);
			}
            x++;
        }
        y++;
    }
}


int	key_hook(int keycode,t_game *game)
{
	int	x_mov;
	int y_mov;

	mlx_clear_window(game->mlx, game->win);
	x_mov = game->player_x;
	y_mov = game->player_y;
	if (keycode == 123)//left
		x_mov--;
	else if (keycode == 124)//right
		x_mov++;
	else if (keycode == 125)//up
		y_mov++;
	else if (keycode == 126)//down
		y_mov--;
	else if (keycode == 53)//esc
		exit(0);
	if (x_mov >= 0 && y_mov >= 0 && game->map[y_mov] && game->map[y_mov][x_mov] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = x_mov;
		game->player_y = y_mov;
		game->map[game->player_y][game->player_x] = 'P';
	}
	printf("%d\n", keycode);
	render_map(game);
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
		game.win = mlx_new_window(game.mlx, (map_width - 1) * TILE_SIZE,map_height * TILE_SIZE, "pacman");
		loading_images(&game);
		render_map(&game);
		mlx_key_hook(game.win, key_hook, &game);
		mlx_loop(game.mlx);
		return (0);
	}
	return (1);
}
