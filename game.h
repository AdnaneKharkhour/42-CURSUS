/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:03:18 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/11 16:18:17 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "mlx.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*player_img;
	void	*player_img_right;
	void	*player_img_left;
	void	*player_img_up;
	void	*player_img_down;
	void	*wall_img;
	void	*floor_img;
	void	*coin_img;
	void	*exit_img;
	void	*open_exit_img;
	void	*enemy_img;
	char	direction;
	int		player_x;
	int		player_y;
	int		score;
	int		moves;
}	t_game;
void	loading_images(t_game *game);
void	player_images(t_game *game, int img_size);
void	other_images(t_game *game, int img_size);
void	key_handle(int keycode, int *x_mov, int *y_mov, t_game *game);
int		key_hook(int keycode, t_game *game);
char	*ft_itoa(int n);
void	display_score(t_game *game);
void	update_game(t_game *game, int x_mov, int y_mov);
int		check_exit(int x, int y, t_game *game);
void	render_map(t_game *game);
void	player_position(t_game *game);
char	**load_map(const char *file);
int		count_coins(t_game *game);
void	put_image(t_game *game, int x, int y);
#endif
