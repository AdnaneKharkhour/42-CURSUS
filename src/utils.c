/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:28:31 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/05 15:34:21 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	calculate_size(t_stack *stack)
{
	t_stack	*tmp;
	int		count;

	tmp = stack;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
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

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

int	get_max_range(t_stack *stack)
{
	int		size;

	size = calculate_size(stack);
	if (size <= 100)
		return (15);
	else if (size <= 500)
		return (35);
	else
		return (50);
}
