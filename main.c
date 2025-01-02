#include "game.h"
#include <stdio.h>

void	loading_images(t_game *game)
{
	int	img_size = 64;

	game->player_img = mlx_xpm_file_to_image(game->mlx, "textures/pacman.xpm", &img_size, &img_size);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &img_size, &img_size);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &img_size, &img_size);
	if(!game->player_img || !game->wall_img || !game->floor_img)
	{
		fprintf(stderr, "Error: Failed to load textures\n");
		exit(1);
	}
}

int main()
{
	t_game game;

	game.mlx = mlx_init();
	
	loading_images(&game);
	
	game.win = mlx_new_window(game.mlx, 1500, 800 , "pacman");

	mlx_loop(game.mlx);
	return (0);
}