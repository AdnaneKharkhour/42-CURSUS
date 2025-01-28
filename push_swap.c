/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:49:17 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/28 18:09:27 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

void	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_space(str[i]) && is_space(str[i + 1]))
		{
			printf("Error\n too many spaces");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	check_doubles(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_args(int argc, char **argv)
{
	int i;
	long n;
	char **str;

	i = 0;
	if (argc == 2)
		str = ft_split(argv[1], ' ');
	else
		str = argv;
	while (i < argc)
	{
		n = ft_atoi(str[i]);
		if (!ft_isdigit(str[i][0]) && str[i][0] != '-' && str[i][0] != '+')
		{
			printf("Error\n not a number");
			exit(EXIT_FAILURE);
		}
		if(check_doubles(argc, str))
		{
			printf("Error\n double number");
			exit(EXIT_FAILURE);
		}
		if (ft_isalpha(str[i][0]))
		{
			printf("Error\n not a number");
			exit(EXIT_FAILURE);
		}
		if (n > INT_MAX || n < INT_MIN)
		{
			printf("Error\n number out of range");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

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

void	add_args_to_stack(t_stack *stack, int count, char **str)
{
	int i;
	int n;

	i = 0;
	while (i < count)
	{
		n = ft_atoi(str[i]);
		ft_nodeadd_back(&stack, ft_newnode(n, i));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a = NULL;
	// t_stack	*stack_b = NULL;
	int count;
	char **str;

	if (argc < 2)
		printf("Error\n not enough arguments");
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		count = 0;
		while (str[count])
			count++;
		add_args_to_stack(stack_a, count, str);
	}
	else
	{
		count = argc - 1;
		add_args_to_stack(stack_a, count, argv + 1);
	}
	affich_stack(stack_a);
	return (0);
}
