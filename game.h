/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:03:18 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/19 18:39:30 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "/Users/akharkho/Desktop/mlx.h"
# include "LIBFT/GET_NEXT_LINE/get_next_line.h"
# include "LIBFT/FT_PRINTF/ft_printf.h"
# include "LIBFT/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

typedef struct s_enemy
{
	int		enemy_x;
	int		enemy_y;
	int		enemy_dir;
	void	*enemy_img;
}	t_enemy;

typedef struct s_bfs_data
{
	bool	**visited;
	int		(*queue)[2];
	int		front;
	int		rear;
	int		dx[4];
	int		dy[4];
	int		collectibles_found;
	int		exit_found;
}	t_bfs_data;

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
	void	*enemy_img_right;
	void	*enemy_img_left;
	t_enemy	*enemies;
	int		num_of_enemies;
	char	direction;
	int		player_x;
	int		player_y;
	int		score;
	int		moves;
	int		map_width;
	int		map_height;
	int		collectibles_count;
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
int		coins_counter(t_game *game);
void	count_map_width_height(t_game *game, int *map_width, int *map_height);
void	put_image(t_game *game, int x, int y);
void	init_enemy(t_game *game);
void	enemy_movement(t_game *game);
void	add_enemy_position(t_game *game);
void	first_check(t_game *game, int *i, int *x);
void	map_check(char *path);
void	check_map_component(t_game *game, int i, int j, int count_player);
void	check_conditions(int count_coins, int count_player, int count_exit);
void	check_map_walls(t_game *game, int i, int j);
void	invalid_map_characters(void);
bool	bfs_check(t_game *game);
void	initialise_variables(t_bfs_data *data);
void	initialise_visited(t_game *game, t_bfs_data *data);
void	initialise_queue(t_game *game, t_bfs_data *data);
bool	is_valid_move(t_game *game, int x, int y, bool **visited);
void	explore_adjacent_cells(t_game *game, t_bfs_data *data, int x, int y);
void	bfs_loop(t_game *game, t_bfs_data *data);
void	free_visited(t_game *game, t_bfs_data *data);
void	count_collectibles_and_exits(t_game *game, int x, int y,
			t_bfs_data *data);
void	free_map(char **map);
#endif
