/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:49:53 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/16 12:28:10 by akharkho         ###   ########.fr       */
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
	pthread_mutex_init(&data->organizer, NULL);
	i = 0;
	while (i < data->num_of_philos)
	{
		philo[i].id = i + 1;
		philo[i].last_time_eaten = get_current_time();
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
	while (1)
	{
		printf("Philo %d is thinking\n", philo->id);
		pthread_mutex_lock(&philo->data->organizer);
		pthread_mutex_lock(philo->left_fork);
		printf("Philo %d picked left fork\n", philo->id);
		pthread_mutex_lock(philo->right_fork);
		printf("Philo %d picked right fork\n", philo->id);
		printf("Philo %d is eating\n", philo->id);
		pthread_mutex_unlock(&philo->data->organizer);
		philo->last_time_eaten = get_current_time();
		philo->num_times_eaten++;
		usleep(philo->data->time_to_eat * 100);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		printf("Philo %d is sleeping\n", philo->id);
		usleep(philo->data->time_to_sleep * 100);
		if (philo->num_times_eaten == philo->data->max_num_to_eat)
			return (NULL);
		if (philo->data->philo_died)
			return (NULL);
	}
	return (NULL);
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
	data.num_of_philos = ft_atoi(argv[1]);
	data.time_to_die = ft_atoi(argv[2]);
	data.time_to_eat = ft_atoi(argv[3]);
	data.time_to_sleep = ft_atoi(argv[4]);
	data.max_num_to_eat = -1;
	data.philo_died = 0;
	if (argc == 6)
		data.max_num_to_eat = ft_atoi(argv[5]);
	philo = malloc(data.num_of_philos * sizeof(t_philo));
	if (!philo)
		return (1);
	init_philo(&data, philo);
	if (create_and_join_threads(data, philo) != 0)
		free_exit(&data, philo);
	free_exit(&data, philo);
	return (0);
}
