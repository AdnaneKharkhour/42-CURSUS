/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:50:14 by akharkho          #+#    #+#             */
/*   Updated: 2025/02/04 17:31:36 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	check_conditions(char **str)
{
	int		j;
	long	n;

	j = 0;
	while (str[j])
	{
		n = ft_atoi(str[j]);
		if (!check_number(str[j]))
		{
			free_split(str);
			exit_error();
		}
		if (n > INT_MAX || n < INT_MIN)
		{
			free_split(str);
			exit_error();
		}
		j++;
	}
}

void	check_args(int argc, char **argv)
{
	int		i;
	char	**str;

	i = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (!str)
			exit_error();
		check_conditions(str);
		free_split(str);
		i++;
	}
}

int	check_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
