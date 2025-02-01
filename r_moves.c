/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:56:37 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/01 19:09:23 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, char *str)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || !stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = tmp;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	if (str)
		printf("%s\n", str);
}

void	reverse_rotate(t_stack **stack, char *str)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || !stack || !(*stack)->next)
		return ;
	tmp = *stack;
	last = tmp;
	while (last->next->next)
		last = last->next;
	*stack = last->next;
	last->next = NULL;
	(*stack)->next = tmp;
	if (str)
		printf("%s\n", str);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, NULL);
	rotate(stack_b, NULL);
	printf("rr\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a, NULL);
	reverse_rotate(stack_b, NULL);
	printf ("rrr\n");
}