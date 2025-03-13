/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:49:53 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/13 11:21:45 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;
	t_data	data;

	if (argc == 4 || argc == 5)
	{
		data.num_of_philos = atoi(argv[1]);
		data.time_to_die = atoi(argv[2]);
		data.time_to_eat = atoi(argv[3]);
		data.time_to_sleep = atoi(argv[4]);
		if (argc == 5)
			data.max_num_to_eat = atoi(argv[5]);
	}
	else
	{
		printf("Error:\n ./philo <num_of_pilo> <time_to_die> <time_to_eat>");
		printf("<time_to_sleep> (<num_of_time_each_philo_can_eat> optional)\n");
		return (1);
	}
}
