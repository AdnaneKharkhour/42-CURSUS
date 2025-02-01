/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:55:18 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/01 18:54:42 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_index(t_stack **stack)
{
	t_stack	*x;
	t_stack	*y;
	int		i;

	if (!stack)
		return ;
	x = *stack;
	while (x)
	{
		y = *stack;
		i = 0;
		while (y)
		{
			if (x->value > y->value)
				i++;
			y = y->next;
		}
		x->index = i;
		x = x->next;
	}
}

void	ft_range(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max;
	int		s;
	int		i;

	while (*stack_b)
	{
		s = ft_nodesize(*stack_b) / 2;
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
	range.max = (ft_nodesize(*stack_a) * 0.048) + 10;
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

void	sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && first < third)
		swap(stack, "sa");
	else if (first > third && third > second)
		rotate(stack, "ra");
	else if (first > second && second > third)
	{
		swap(stack, "sa");
		reverse_rotate(stack, "rra");
	}
	else if (first < second && first > third)
		reverse_rotate(stack, "rra");
	else if (first < second && first < third && second > third)
	{
		rotate(stack, "ra");
		swap(stack, "sa");
		reverse_rotate(stack, "rra");
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	min;

	min = (ft_minnode(*stack_a))->index;
	size = ft_nodesize(*stack_a) / 2;
	if (min < size)
	{
		while ((*stack_a)->index != min)
			rotate (stack_a, "ra");
	}
	else
	{
		while ((*stack_a)->index != min)
			reverse_rotate(stack_a, "rra");
	}
	push(stack_b, stack_a, "pb");
	sort_three(stack_a);
	push(stack_a, stack_b, "pa");
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	min;

	min = (ft_minnode(*stack_a))->index;
	size = ft_nodesize(*stack_a) / 2;
	if (min < size)
	{
		while ((*stack_a)->index != min)
			rotate(stack_a, "ra");
	}
	else
	{
		while ((*stack_a)->index != min)
			reverse_rotate(stack_a, "rra");
	}
	push(stack_b, stack_a, "pb");
	sort_four(stack_a, stack_b);
	push(stack_a, stack_b, "pa");
}

void	handle_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_nodesize(*stack_a);
	if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
		filter_stack(stack_a, stack_b);
}
