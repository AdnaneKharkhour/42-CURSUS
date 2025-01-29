/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:49:17 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/29 11:26:35 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

int	check_doubles(t_stack *stack, int n)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->value == n)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_args(int argc, char **argv)
{
	int		i;
	int		j;
	long	n;
	char	**str;

	i = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (!str)
		{
			printf("Error\nMemory allocation failed\n");
			exit(EXIT_FAILURE);
		}
		j = 0;
		while (str[j])
		{
			n = ft_atoi(str[j]);
			if (!check_number(str[j]))
			{
				printf("Error\nInvalid input:\n");
				free_split(str);
				exit(EXIT_FAILURE);
			}
			if (n > INT_MAX || n < INT_MIN)
			{
				printf("Error\nNumber is too large:\n");
				free_split(str);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		free_split(str);
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
	// t_stack	*stack_b = NULL;
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
	affich_stack(stack_a);
	return (0);
}
