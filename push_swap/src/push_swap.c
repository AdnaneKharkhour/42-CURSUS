/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:49:17 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/06 10:50:45 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
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
			free_split(str);
			free_stack(stack);
			exit_error();
		}
		new_node = ft_newnode(n, i);
		if (!new_node)
		{
			free_split(str);
			free_stack(stack);
			exit_error();
		}
		ft_nodeadd_back(stack, new_node);
		i++;
	}
}

void	check_empty_or_all_space(char **argv, int i, t_stack **stack_a)
{
	int	j;

	j = 0;
	if (argv[i][j] == '\0')
	{
		free_stack(stack_a);
		exit_error();
	}
	while (argv[i][j] == ' ')
		j++;
	if (argv[i][j] == '\0')
	{
		free_stack(stack_a);
		exit_error();
	}
}

void	handle_args(int argc, char **argv, t_stack **stack_a)
{
	int		count;
	int		i;
	char	**str;

	check_args(argc, argv);
	i = 1;
	while (i < argc)
	{
		check_empty_or_all_space(argv, i, stack_a);
		str = ft_split(argv[i], ' ');
		if (!str)
			exit_error();
		count = 0;
		while (str[count])
			count++;
		add_args_to_stack(stack_a, count, str);
		free_split(str);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	else
	{
		stack_a = NULL;
		stack_b = NULL;
		handle_args(argc, argv, &stack_a);
		if (check_sorted(stack_a))
		{
			free_stack(&stack_a);
			exit(EXIT_SUCCESS);
		}
		sort_index(&stack_a);
		handle_sort(&stack_a, &stack_b);
		free_stack(&stack_a);
	}
	return (0);
}
