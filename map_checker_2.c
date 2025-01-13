/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:30:58 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/13 19:13:07 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdbool.h>

void	invalid_map_characters(void)
{
	ft_printf("Error: Invalid character in map");
	exit(EXIT_FAILURE);
}
