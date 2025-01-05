#include "game.h"
#include <stdio.h>
#define TILE_SIZE 64

void	loading_images(t_game *game)
{
	int	img_size;

	img_size = TILE_SIZE;
	game->player_img = mlx_xpm_file_to_image(game->mlx, "textures/pacman.xpm", &img_size, &img_size);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &img_size, &img_size);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &img_size, &img_size);
	if(!game->player_img || !game->wall_img || !game->floor_img)
	{
		fprintf(stderr, "Error: Failed to load textures\n");
		exit(1);
	}
}

void render_map(t_game *game) {
    int y, x;
    y = 0;

    while (game->map[y]) {
        x = 0;
        while (game->map[y][x]) {
            mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x * TILE_SIZE, y * TILE_SIZE);
            if (game->map[y][x] == '1') {
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
            } else if (game->map[y][x] == 'P') {
                mlx_put_image_to_window(game->mlx, game->win, game->player_img, x * TILE_SIZE, y * TILE_SIZE);
            }

            x++;
        }
        y++;
    }
}


int	key_hook(int keycode,	t_game *game)
{
	int	x_mov,y_mov;

	x_mov = game->player_x;
	y_mov = game->player_y;
	if (keycode == 123)
		x_mov--;
	else if (keycode == 124)
		x_mov++;
	else if (keycode == 125)
		y_mov++;
	else if (keycode == 126)
		y_mov--;
	else if (keycode == 53)
		mlx_destroy_window(game->mlx, game->win);
	if (game->map[y_mov][x_mov] != '1')
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

int main()
{
	char *map[] = {
    "1111111111",
    "1000000001",
    "1000000001",
    "1000P00001",
    "1000000001",
    "1000000001",
    "1000000001",
    "1111111111",
    NULL
	};

	t_game game;

	game.mlx = mlx_init();

	game.map = map;
	game.player_x = 4;
	game.player_y = 3;

	game.win = mlx_new_window(game.mlx, 10 * TILE_SIZE,8 * TILE_SIZE, "pacman");
	loading_images(&game);

	render_map(&game);

	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
