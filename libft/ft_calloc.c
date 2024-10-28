/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:12:58 by akharkho          #+#    #+#             */
/*   Updated: 2024/10/28 19:19:18 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;

	p = malloc(count * size);
	ft_bzero(p, count);
	return (p);
}
