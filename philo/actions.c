/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 08:02:29 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/18 15:52:45 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(int id)
{
	printf("Philo %d is thinking\n", id);
}

void	eat(t_philo *philo)
{
	if (philo->data->philo_died)
		return ;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		printf("Philo %d picked right fork\n", philo->id);
		pthread_mutex_lock(philo->left_fork);
		printf("Philo %d picked left fork\n", philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		printf("Philo %d picked left fork\n", philo->id);
		pthread_mutex_lock(philo->right_fork);
		printf("Philo %d picked right fork\n", philo->id);
	}
	pthread_mutex_lock(&philo->data->organizer);
	printf("Philo %d is eating\n", philo->id);
	philo->last_time_eaten = get_current_time();
	philo->num_times_eaten++;
	pthread_mutex_unlock(&philo->data->organizer);
	ft_usleep(philo->data->time_to_eat * 1000, philo->data);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_sleeping(t_philo *philo)
{
	printf("Philo %d is sleeping\n", philo->id);
	ft_usleep(philo->data->time_to_sleep * 1000, philo->data);
}
