#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define TILE_SIZE 64
typedef	struct	s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*player_img;
	void	*wall_img;
	void	*floor_img;
	void	*coin_img;
	void	*exit_img;
	int		player_x;
	int		player_y;
	int		score;
	int		moves;
}	t_game;
#ifndef MAP_H
#define MAP_H
char	**load_map(const char *file);
void	player_position(t_game *game);
#endif
