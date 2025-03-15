/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:49:53 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/15 12:55:41 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	data->forks = malloc(data->num_of_philos * sizeof(pthread_mutex_t));
	if (!data->forks)
		exit(1);
	while (i < data->num_of_philos)
		pthread_mutex_init(&data->forks[i++], NULL);
	i = 0;
	while (i < data->num_of_philos)
	{
		philo[i].id = i + 1;
		philo[i].last_time_eaten = 0;
		philo[i].num_times_eaten = 0;
		philo[i].data = data;
		philo[i].left_fork = &data->forks[i];
		philo[i].right_fork = &data->forks[(i + 1) % data->num_of_philos];
		i++;
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("Philo %d is thinking\n", philo->id);
	usleep(1000000);
	return (NULL);
}

int	free_exit(t_data *data, t_philo *philo)
{
	if (philo)
		free(philo);
	if (data->forks)
		free(data->forks);
	return (1);
}

int	create_and_join_threads(t_data data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data.num_of_philos)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]) != 0)
		{
			printf("failed creating thread for philo %d", (i + 1));
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < data.num_of_philos)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
		{
			printf("failed joining thread for philo %d", (i + 1));
			free(philo);
			free(data.forks);
			return (1);
		}
		i++;
	}
	return (0);
}

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
	data.num_of_philos = atoi(argv[1]);
	data.time_to_die = atoi(argv[2]);
	data.time_to_eat = atoi(argv[3]);
	data.time_to_sleep = atoi(argv[4]);
	data.max_num_to_eat = -1;
	if (argc == 5)
		data.max_num_to_eat = atoi(argv[5]);
	philo = malloc(data.num_of_philos * sizeof(t_philo));
	if (!philo)
		exit(1);
	init_philo(&data, philo);
	create_and_join_threads(data, philo);
	free(philo);
	free(data.forks);
	return (0);
}
