/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:55:18 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/03 15:37:21 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*ft_maxnode(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*max;

	if (!stack)
		return (NULL);
	tmp = stack;
	max = stack;
	while (tmp)
	{
		if (tmp->value > max->value)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	max_node_position(t_stack *stack, int max_index)
{
	int		i;

	i = 0;
	while (stack && stack->index != max_index)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ft_range(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max;
	int		s;
	int		i;

	while (*stack_b)
	{
		s = calculate_size(*stack_b) / 2;
		max = ft_maxnode(*stack_b);
		i = max->index;
		if (max_node_position(*stack_b, i) < s)
		{
			while ((*stack_b)->index != i)
				rotate(stack_b, "rb");
		}
		else
		{
			while ((*stack_b)->index != i)
				reverse_rotate(stack_b, "rrb");
		}
		push(stack_a, stack_b, "pa");
	}
}

void	filter_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_range	range;

	range.min = 0;
	range.max = calculate_size(*stack_a) / 20 + 10;
	while (*stack_a)
	{
		if ((*stack_a)->index >= range.min && (*stack_a)->index <= range.max)
		{
			push(stack_b, stack_a, "pb");
			range.min++;
			range.max++;
		}
		else if ((*stack_a)->index > range.max)
			rotate(stack_a, "ra");
		else if ((*stack_a)->index < range.min)
		{
			push(stack_b, stack_a, "pb");
			rotate(stack_b, "rb");
			range.min++;
			range.max++;
		}
	}
	ft_range(stack_a, stack_b);
}

t_stack	*ft_minnode(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*min;

	if (!stack)
		return (NULL);
	tmp = stack;
	min = stack;
	while (tmp)
	{
		if (tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}
