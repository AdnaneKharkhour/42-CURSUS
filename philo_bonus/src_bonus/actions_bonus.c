/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 08:02:29 by akharkho          #+#    #+#             */
/*   Updated: 2025/04/06 14:58:42 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	print_msg(char *msg, t_philo *philo)
{
	sem_wait(philo->data->msg);
	printf("%zd %d %s\n", get_time() - philo->data->start, philo->id, msg);
	sem_post(philo->data->msg);
}

void	think(t_philo *philo)
{
	print_msg("is thinking", philo);
}

void	eat(t_philo *philo)
{
	sem_wait (philo->data->forks);
	print_msg("has taken a fork", philo);
	sem_wait (philo->data->forks);
	print_msg("has taken a fork", philo);
	print_msg("is eating", philo);
	last_eat(philo, 1, 0, 0);
	ft_usleep(philo->data->time_to_eat, philo->data);
	last_eat(philo, 2, 0, 0);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	philo_sleeping(t_philo *philo)
{
	print_msg("is sleeping", philo);
	ft_usleep(philo->data->time_to_sleep, philo->data);
}

void	routine(t_philo *philo)
{
	pthread_t	monitor_thread;

	pthread_create(&monitor_thread, NULL, monitor, philo);
	if (philo->data->num_of_philos == 1)
	{
		sem_wait(philo->data->forks);
		print_msg("has taken a fork", philo);
		usleep(philo->data->time_to_die * 1000);
		sem_post(philo->data->forks);
		exit(0);
	}
	while (1)
	{
		if (philo->num_times_eaten != philo->data->max_num_to_eat)
		{
			eat(philo);
			philo_sleeping(philo);
			think(philo);
		}
	}
}
