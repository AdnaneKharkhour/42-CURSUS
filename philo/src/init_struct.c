/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:54:22 by akharkho          #+#    #+#             */
/*   Updated: 2025/04/06 16:00:57 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	data->forks = malloc(data->num_of_philos * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (free(philo), 1);
	i = 0;
	while (i < data->num_of_philos)
		pthread_mutex_init(&data->forks[i++], NULL);
	if (pthread_mutex_init(&data->organizer, NULL) != 0
		|| pthread_mutex_init(&data->msg, NULL) != 0
		|| pthread_mutex_init(&data->eat, NULL) != 0)
		return (free_exit(data, philo), 1);
	i = 0;
	while (i < data->num_of_philos)
	{
		philo[i].id = i + 1;
		philo[i].last_time_eaten = get_time();
		philo[i].num_times_eaten = 0;
		philo[i].data = data;
		philo[i].left_fork = &data->forks[i];
		philo[i].right_fork = &data->forks[(i + 1) % data->num_of_philos];
		i++;
	}
	return (0);
}

void	init_data(char **argv, int argc, t_data *data)
{
	data->num_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->max_num_to_eat = -1;
	data->philo_died = 0;
	data->start = get_time();
	if (argc == 6)
	{
		data->max_num_to_eat = ft_atoi(argv[5]);
	}
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

int	check_args(t_data *data, int argc)
{
	if (data->num_of_philos <= 0 || data->time_to_die < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0)
	{
		printf("Error:\n invalid value in args");
		return (1);
	}
	if (argc == 6)
	{
		if (data->max_num_to_eat < 0)
		{
			printf("Error:\n invalid value in args");
			return (1);
		}
	}
	return (0);
}
