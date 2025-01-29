/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:02:05 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/29 11:01:50 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "LIBFT/libft.h"
# include <stdlib.h>
# include <unistd.h>

int		check_doubles(t_stack *stack, int n);
void	check_args(int argc, char **argv);
int		check_argument(char **argv);


#endif