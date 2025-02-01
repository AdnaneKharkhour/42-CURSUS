/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:02:05 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/01 13:31:36 by akharkho         ###   ########.fr       */
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
//sort.c
void	swap(t_stack **stack, char *str);
void	push(t_stack **stack_a, t_stack **stack_b, char *str);
void	rotate(t_stack **stack, char *str);
void	reverse_rotate(t_stack **stack, char *str);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
//sort2.c
t_stack	*ft_maxnode(t_stack *stack);
int		max_node_position(t_stack *stack, int max_index);
void	sort_index(t_stack **stack);
void	ft_range(t_stack **stack_a, t_stack **stack_b);
void	filter_stack(t_stack **stack_a, t_stack **stack_b);
void	handle_sort(t_stack **stack_a, t_stack **stack_b);

#endif