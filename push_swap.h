/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:02:05 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/31 19:17:31 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "LIBFT/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct range
{
	int		min;
	int		max;
}	t_range;


//check_args.c
int		check_doubles(t_stack *stack, int n);
void	check_args(int argc, char **argv);
void	check_conditions(char **str);
int		check_number(char *str);
int		check_sorted(t_stack *stack);

//utils.c
void	free_split(char **str);
int		calculate_size(t_stack *stack);
//push_swap.c
void	affich_stack(t_stack *stack);
void	add_args_to_stack(t_stack **stack, int count, char **str);


#endif