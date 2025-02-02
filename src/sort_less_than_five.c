/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:35:57 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/02 18:52:20 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **stack)
{
	int	nbr1;
	int	nbr2;
	int	nbr3;

	nbr1 = (*stack)->value;
	nbr2 = (*stack)->next->value;
	nbr3 = (*stack)->next->next->value;
	if (nbr1 > nbr2 && nbr1 < nbr3)
		swap(stack, "sa");
	else if (nbr1 > nbr3 && nbr3 > nbr2)
		rotate(stack, "ra");
	else if (nbr1 > nbr2 && nbr2 > nbr3)
	{
		swap(stack, "sa");
		reverse_rotate(stack, "rra");
	}
	else if (nbr1 < nbr2 && nbr1 > nbr3)
		reverse_rotate(stack, "rra");
	else if (nbr1 < nbr2 && nbr1 < nbr3 && nbr2 > nbr3)
	{
		swap(stack, "sa");
		rotate(stack, "ra");
	}
}

void	get_min(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	size;

	size = calculate_size(*stack_a);
	min = (ft_minnode(*stack_a))->index;
	if (min > size / 2)
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
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	get_min(stack_a, stack_b);
	sort_three(stack_a);
	push(stack_a, stack_b, "pa");
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	get_min(stack_a, stack_b);
	get_min(stack_a, stack_b);
	sort_three(stack_a);
	push(stack_a, stack_b, "pa");
	push(stack_a, stack_b, "pa");
}

void	handle_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = calculate_size(*stack_a);
	if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
		filter_stack(stack_a, stack_b);
}
