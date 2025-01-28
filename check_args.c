/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:50:14 by akharkho          #+#    #+#             */
/*   Updated: 2025/01/28 18:06:46 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_argument(char **argv)
{
	int i;
	int j;
	int flag;

	i = 0;
	flag = 0;
	while (argv[i])
	{
		j = 0;
		if (is_space(argv[i][j]))
			flag = 1;
		if (is_space(argv[i][j]) && is_space(argv[i][j + 1]))
		{
			printf("Error\n too many spaces");
			exit(EXIT_FAILURE);
		}
		else if ((argv[i][j] == '-' || argv[i][j] == '+') && !ft_isdigit(argv[i][j + 1]))
		{
			printf("Error\n double sign");
			exit(EXIT_FAILURE);
		}
		else if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-' && argv[i][j] != '+')
		{
			printf("Error\n not a digit");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (flag);
}
