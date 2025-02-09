/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:02:05 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/06 10:28:31 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"

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
void	sort_index(t_stack **stack);
void	free_stack(t_stack **stack);
int		get_max_range(t_stack *stack);
//push_swap.c
void	exit_error(void);
void	add_args_to_stack(t_stack **stack, int count, char **str);
void	handle_args(int argc, char **argv, t_stack **stack_a);
void	check_empty_or_all_space(char **argv, int i, t_stack **stack_a);
//sort.c
t_stack	*ft_maxnode(t_stack *stack);
int		max_node_position(t_stack *stack, int max_index);
void	ft_range(t_stack **stack_a, t_stack **stack_b);
void	filter_stack(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_minnode(t_stack *stack);
//sort_less_than_five.c
void	sort_three(t_stack **stack);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	handle_sort(t_stack **stack_a, t_stack **stack_b);
//moves.c
void	swap(t_stack **stack, char *str);
void	push(t_stack **stack_a, t_stack **stack_b, char *str);
void	ss(t_stack **stack_a, t_stack **stack_b);
//r_moves.c
void	rotate(t_stack **stack, char *str);
void	reverse_rotate(t_stack **stack, char *str);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
#endif