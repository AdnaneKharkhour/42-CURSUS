/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:42:31 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/23 13:56:02 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	check_rectangle(t_game *game)
{
	int	i;
	int	j;
	int	first_row;

	first_row = 0;
	if (!game->map[0])
	{
		ft_printf("Error:\nEmpty map\n");
		exit(EXIT_FAILURE);
	}
	while (game->map[0][first_row])
		first_row++;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
			j++;
		if (j != first_row)
		{
			ft_printf("Error:\ngame->map isn't rectangular\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_map_walls(t_game *game, int i, int j)
{
	int	last_row;

	last_row = 0;
	while (game->map[last_row])
		last_row++;
	while (game->map[0][j] && game->map[last_row - 1][j])
	{
		if (game->map[0][j] != '1' || game->map[last_row - 1][j] != '1')
		{
			ft_printf("Error:\ntop or bottom missing a wall\n");
			exit(EXIT_FAILURE);
		}
		j++;
	}
	while (game->map[i])
	{
		if (game->map[i][j - 1] != '1' || game->map[i][0] != '1')
		{
			ft_printf("Error:\nthe right or left walls are missing\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_conditions(int count_coins, int count_player, int count_exit)
{
	if (count_coins <= 0)
	{
		ft_printf("Error:\nmap should have at least 1 coin\n");
		exit(EXIT_FAILURE);
	}
	if (count_player > 1 || count_player == 0)
	{
		ft_printf("Error:\nmap should have 1 player\n");
		exit(EXIT_FAILURE);
	}
	if (count_exit > 1 || count_exit == 0)
	{
		ft_printf("Error:\nmap should have 1 exit\n");
		exit(EXIT_FAILURE);
	}
}

void	check_map_component(t_game *game, int i, int j,
		int count_player)
{
	int		count_coins;
	int		count_exit;

	count_coins = coins_counter(game);
	count_exit = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				count_coins++;
			if (game->map[i][j] == 'E')
				count_exit++;
			if (game->map[i][j] == 'P')
				count_player++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0' 
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P')
				invalid_map_characters();
			j++;
		}
		i++;
	}
	check_conditions(count_coins, count_player, count_exit);
}

void	map_check(char *path)
{
	int		i;
	int		j;
	int		count_player;
	t_game	game;

	i = 0;
	j = 0;
	count_player = 0;
	while (path[i] != '.')
		i++;
	if (path[i - 1] == '/' || path[i - 1] == '\0' || (path[i - 1] != '.' 
			&& (path[i + 1] != 'b' || path[i + 2] != 'e'
				|| path[i + 3] != 'r' || path[i + 4] != '\0')))
	{
		ft_printf("Error:\nInvalid path\n");
		exit(1);
	}
	i = 0;
	game.map = load_map(path);
	check_rectangle(&game);
	check_map_walls(&game, i, j);
	check_map_component(&game, i, j, count_player);
	free_map(game.map);
}
