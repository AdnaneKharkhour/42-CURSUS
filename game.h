#include "mlx.h"
#include <stdlib.h>

typedef	struct	s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*player_img;
	void	*wall_img;
	void	*floor_img;
	int		player_x;
	int		player_y;
}	t_game;
