/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:03:18 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/21 12:48:56 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_BONUS_H
# define GAME_BONUS_H
# include "/Users/akharkho/Desktop/mlx.h"
# include "../LIBFT/GET_NEXT_LINE/get_next_line.h"
# include "../LIBFT/FT_PRINTF/ft_printf.h"
# include "../LIBFT/libft/libft.h"
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
//controls.c
void	key_handle(int keycode, int *x_mov, int *y_mov, t_game *game);
int		check_exit(int x_mov, int y_mov, t_game *game);
void	update_game(t_game *game, int x_mov, int y_mov);
int		key_hook(int keycode, t_game *game);
//enemy.c
void	add_enemy_position(t_game *game);
void	init_enemy(t_game *game);
void	first_check(t_game *game, int *i, int *x);
void	enemy_movement(t_game *game);
//load_images.c
void	player_images(t_game *game, int img_size);
void	enemy_images(t_game *game, int img_size);
void	other_images(t_game *game, int img_size);
void	loading_images(t_game *game);
//main.c
int		game_loop(t_game *game);
void	initialise_struct(t_game *game);
void	check_if_playable(t_game *game, char **argv);
int		main(int argc, char **argv);
//map_checker_2.c
void	invalid_map_characters(void);
bool	is_valid_move(t_game *game, int x, int y, bool **visited);
void	initialise_variables(t_bfs_data *data);
void	initialise_visited(t_game *game, t_bfs_data *data);
void	initialise_queue(t_game *game, t_bfs_data *data);
//map_checker_3.c
void	explore_adjacent_cells(t_game *game, t_bfs_data *data, int x, int y);
void	free_visited(t_game *game, t_bfs_data *data);
void	count_collectibles_and_exits(t_game *game, int x,
			int y, t_bfs_data *data);
void	bfs_loop(t_game *game, t_bfs_data *data);
bool	bfs_check(t_game *game);
//map_checker.c
void	check_rectangle(t_game *game);
void	check_map_walls(t_game *game, int i, int j);
void	check_conditions(int count_coins, int count_player, int count_exit);
void	check_map_component(t_game *game, int i, int j,
			int count_player);
void	map_check(char *path);
//map.c
int		count_lines(const char *file);
void	remove_nl(char *line);
char	**load_map(const char *file);
void	player_position(t_game *game);
void	free_map(char **map);
//render_map.c
void	put_image(t_game *game, int x, int y);
void	render_map(t_game *game);
//utils.c
char	*ft_itoa(int n);
void	display_score(t_game *game);
int		coins_counter(t_game *game);
void	count_map_width_height(t_game *game, int *width, int *height);
#endif
