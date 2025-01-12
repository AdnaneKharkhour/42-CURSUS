/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:42:31 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/12 19:35:43 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	map_check(char *path)
{
	int	i;

	i = 0;
	while (path[i] != '.')
		i++;
	if (path[i + 1] != 'b' || path[i + 2] != 'e' || path[i + 3] != 'r')
	{
		ft_printf("Error: Invalid path\n");
		exit(1);
	}
}
