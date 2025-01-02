#include <mlx.h>
#include <stdlib.h>

typedef	struct	s_game
{
	void	*mlx;
	void	*win;
	void	*player_img;
	void	*wall_img;
	void	*floor_img;
	int		win_height;
	int		win_width;
}	t_game;
