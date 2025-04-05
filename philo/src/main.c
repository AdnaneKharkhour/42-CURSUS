/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:49:53 by akharkho          #+#    #+#             */
/*   Updated: 2025/04/05 16:57:02 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		printf("Error:\n ./philo <num_of_pilo> <time_to_die> <time_to_eat>");
		printf("<time_to_sleep> (<num_of_time_each_philo_can_eat> optional)\n");
		return (1);
	}
	init_data(argv, argc, &data);
	if (check_args(&data, argc))
		return (1);
	philo = malloc(data.num_of_philos * sizeof(t_philo));
	if (!philo)
		return (1);
	init_philo(&data, philo);
	if (create_and_join_threads(data, philo) != 0)
		return (free_exit(&data, philo));
	free_exit(&data, philo);
	return (0);
}
