/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:35:57 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/31 18:25:02 by kali             ###   ########.fr       */
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
		peintf("%s\n", str);
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

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, NULL);
	swap(stack_b, NULL);
	printf("ss\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, NULL);
	rotate(stack_b ,NULL);
	printf("rr\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a, NULL);
	reverse_rotate(stack_b, NULL);
	printf ("rrr\n");
}
