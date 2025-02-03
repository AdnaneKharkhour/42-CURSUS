/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:49:54 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/03 18:44:25 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_moves_conditions(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		swap(stack_a, NULL);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap(stack_b, NULL);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(line, "pa\n", 3))
		push(stack_a, stack_b, NULL);
	else if (!ft_strncmp(line, "pb\n", 3))
		push(stack_b, stack_a, NULL);
	else if (!ft_strncmp(line, "ra\n", 3))
		rotate(stack_a, NULL);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate(stack_b, NULL);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(line, "rra\n", 4))
		reverse_rotate(stack_a, NULL);
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse_rotate(stack_b, NULL);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(stack_a, stack_b);
	else
		exit_error(NULL);
}

void	check_moves(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		check_moves_conditions(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
}
