/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:40:03 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/15 16:56:46 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		nb;

	nb = n;
	len = 0;
	if (nb == 0)
		return (ft_strdup("0", 2));
	while (nb)
	{
		len++;
		nb /= 10;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

void	display_score(t_game *game)
{
	char	*score;
	char	*moves;

	score = ft_itoa(game->score);
	moves = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 10, 10, 0x00FFFFFF, "Score: ");
	mlx_string_put(game->mlx, game->win, 70, 10, 0x00FFFFFF, score);
	mlx_string_put(game->mlx, game->win, 10, 30, 0x00FFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 70, 30, 0x00FFFFFF, moves);
}

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
	while (game->map[0][*width])
		(*width)++;
	while (game->map[*height])
		(*height)++;
	return ;
}
