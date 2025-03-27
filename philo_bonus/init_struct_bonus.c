/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:54:22 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/27 15:35:05 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	sem_unlink("/forks");
	sem_unlink("/organizer");
	sem_unlink("/msg");
	sem_unlink("/eat");
	data->forks = sem_open("/forks", O_CREAT, 0644, data->num_of_philos);
	data->organizer = sem_open("/organizer", O_CREAT, 0644, 1);
	data->msg = sem_open("/msg", O_CREAT, 0644, 1);
	data->eat = sem_open("/eat", O_CREAT, 0644, 1);
	if (!data->forks || !data->organizer || !data->msg || !data->eat)
	{
		printf("Error:\n failed semopen");
		exit(EXIT_FAILURE);
	}
	data->pids = malloc(sizeof(int) * data->num_of_philos);
	if (!data->pids)
	{
		printf("Error:\n failed to allocate for pids");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < data->num_of_philos)
	{
		data->pids[i] = fork();
		if (data->pids[i] == 0)
		{
			philo[i].id = i + 1;
			philo[i].last_time_eaten = get_time();
			philo[i].num_times_eaten = 0;
			philo[i].data = data;
			routine(philo);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
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

int	check_args(t_data *data, int argc)
{
	if (data->num_of_philos < 0 || data->time_to_die < 0
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
