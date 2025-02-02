/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:36:33 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/02 18:52:12 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
