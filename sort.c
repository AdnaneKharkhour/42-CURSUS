/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:35:57 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/01 18:56:36 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char *str)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	(*stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (str)
		printf("%s\n", str);
}

void	push(t_stack **stack_a, t_stack **stack_b, char *str)
{
	t_stack	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_b;
	(*stack_b) = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	if (str)
		printf("%s\n", str);
}


void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, NULL);
	swap(stack_b, NULL);
	printf("ss\n");
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
