/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:49:17 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/31 19:32:07 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void affich_stack(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}



void	add_args_to_stack(t_stack **stack, int count, char **str)
{
	int		i;
	long	n;
	t_stack	*new_node;

	i = 0;
	while (i < count)
	{
		n = ft_atoi(str[i]);
		if (check_doubles(*stack, n))
		{
			printf("Error\nDuplicate number: %ld\n", n);
			exit(EXIT_FAILURE);
		}
		new_node = ft_newnode(n, i);
		if (!new_node)
		{
			printf("Error\nallocation failed\n");
			exit(EXIT_FAILURE);
		}
		ft_nodeadd_back(stack, new_node);
		i++;
	}
}


int	main(int argc, char **argv)
{
	t_stack	*stack_a = NULL;
	t_stack	*stack_b = NULL;
	int count;
	int	i;
	char **str;

	if (argc < 2)
		printf("Error\n not enough arguments");
	else
	{
		check_args(argc, argv);
		i = 1;
		while (i < argc)
		{
			if (argv[i][0] == '\0')
			{
				printf("Error\nEmpty argument\n");
				exit(EXIT_FAILURE);
			}
			str = ft_split(argv[i], ' ');
			if (!str)
				exit(EXIT_FAILURE);
			count = 0;
			while (str[count])
				count++;
			add_args_to_stack(&stack_a, count, str);
			free_split(str);
			i++;
		}
	}
	if (check_sorted(stack_a))
		exit(EXIT_SUCCESS);
	affich_stack(stack_a);
	filter_stack(&stack_a, &stack_b);
	return (0);
}
