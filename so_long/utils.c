/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:40:03 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/20 19:54:15 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	coins_counter(t_game *game)
{
	int	coins;
	int	i;
	int	j;

	i = 0;
	coins = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	return (coins);
}

void	count_map_width_height(t_game *game, int *width, int *height)
{
	*width = 0;
	*height = 0;
	while (game->map[0][*width])
		(*width)++;
	while (game->map[*height])
		(*height)++;
	return ;
}
