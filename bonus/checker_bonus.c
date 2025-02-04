/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:49:17 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/04 17:38:42 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	affich_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("%d\n", tmp->value);
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
		check_moves(&stack_a, &stack_b);
		if (check_sorted(stack_a) && !stack_b)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_stack(&stack_a);
		if (stack_b)
			free_stack(&stack_b);
	}
	return (0);
}
