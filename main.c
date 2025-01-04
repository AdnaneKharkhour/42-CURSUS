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
    int y;
	int	x;

	y = 0;
    while (game->map[y]) {
        x = 0;
        while (game->map[y][x]) {
            void *img_to_draw = NULL;

            if (game->map[y][x] == '1') {
                img_to_draw = game->wall_img;
            } else if (game->map[y][x] == '0') {
                img_to_draw = game->floor_img;
            } else if (game->map[y][x] == 'P') {
                img_to_draw = game->player_img;
            }

            if (img_to_draw) {
                mlx_put_image_to_window(game->mlx, game->win, img_to_draw, x * TILE_SIZE, y * TILE_SIZE);
            } else {
                fprintf(stderr, "Error: Unknown map character '%c'\n", game->map[y][x]);
                exit(1);
            }

            x++;
        }
        y++;
    }
}

int main()
{
	char *map[] = {
    "111111",
    "100001",
    "100P01",
    "100001",
    "111111",
    NULL
	};

	t_game game;

	game.mlx = mlx_init();
	
	game.map = map;

	game.win = mlx_new_window(game.mlx, 1500,900, "pacman");

	loading_images(&game);

	render_map(&game);

	mlx_loop(game.mlx);
	return (0);
}
