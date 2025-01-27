/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:49:17 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/27 19:21:38 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

void	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (is_space(argv[i][j]) && is_space(argv[i][j + 1]))
			{
				printf("Error\n unvalid argument more than one space");
				exit(EXIT_FAILURE);
			}
			if ((argv[i][j] == '-' || argv[i][j] == '+')
				&& !ft_isdigit(argv[i][j + 1]))
			{
				printf("Error\n unvalid argument more than one sign");
				exit(EXIT_FAILURE);
			}
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-'
				&& argv[i][j] != '+')
			{
				printf("Error\n unvalid argument not digit");
				exit(EXIT_FAILURE);
			}
			if (ft_isalpha(argv[i][j]))
			{
				printf("Error\n unvalid argument alpha");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

int	*parse_numbers(int argc, char **argv)
{
	int	*numbers;
	int	i;

	numbers = (int *)malloc(sizeof(int) * (argc - 1));
	if (!numbers)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		numbers[i - 1] = atoi(argv[i]);
		i++;
	}
	return (numbers);
}

int	main(int argc, char **argv)
{
	int	*numbers;
	int i;

	if (argc < 2)
		printf("Error\n not enough arguments");
	else
	{
		check_args(argc, argv);
		numbers = parse_numbers(argc, argv);
		if (!numbers)
		{
			printf("Error\n malloc error");
			return (1);
		}
		i = 0;
		while (i < argc - 1)
		{
			printf("%d\n", numbers[i]);
			i++;
		}
	}
	return (0);
}
