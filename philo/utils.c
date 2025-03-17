/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 08:02:32 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/17 11:26:04 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	t_time	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

int	create_and_join_threads(t_data data, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_create(&data.monitor_thread, NULL, monitor, philo);
	while (i < data.num_of_philos)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]) != 0)
		{
			printf("failed creating thread for philo %d\n", (i + 1));
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < data.num_of_philos)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
		{
			printf("failed joining thread for philo %d\n", (i + 1));
			return (1);
		}
		i++;
	}
	pthread_join(data.monitor_thread, NULL);
	return (0);
}

int	free_exit(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	if (philo)
		free(philo);
	if (data->forks)
	{
		while (i < data->num_of_philos)
			pthread_mutex_destroy(&data->forks[i++]);
		free(data->forks);
	}
	pthread_mutex_destroy(&data->organizer);
	return (1);
}
