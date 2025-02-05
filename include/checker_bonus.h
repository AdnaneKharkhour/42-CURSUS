/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:33:56 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/05 15:40:48 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct range
{
	int		min;
	int		max;
}	t_range;

//check_args_bonus.c
int		check_doubles(t_stack *stack, int n);
void	check_args(int argc, char **argv);
void	check_conditions(char **str);
int		check_number(char *str);
int		check_sorted(t_stack *stack);
//check_moves_bonus.c
void	check_moves(t_stack **stack_a, t_stack **stack_b);
void	check_moves_conditions(t_stack **stack_a,
			t_stack **stack_b, char *line);
void	exit_error(void);
//utils_bonus.c
void	free_split(char **str);
int		calculate_size(t_stack *stack);
void	sort_index(t_stack **stack);
void	free_stack(t_stack **stack);
void	exit_error(void);
//checker.c
void	affich_stack(t_stack *stack);
void	add_args_to_stack(t_stack **stack, int count, char **str);
void	check_empty_or_all_space(char **argv, int i, t_stack **stack_a);
void	handle_args(int argc, char **argv, t_stack **stack_a);
//moves_bonus.c
void	swap(t_stack **stack, char *str);
void	push(t_stack **stack_a, t_stack **stack_b, char *str);
void	ss(t_stack **stack_a, t_stack **stack_b);
//r_moves_bonus.c
void	rotate(t_stack **stack, char *str);
void	reverse_rotate(t_stack **stack, char *str);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
#endif