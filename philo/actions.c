/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 08:02:29 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/20 17:35:51 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	printf("%zd Philo %d is thinking\n", get_current_time(philo->data->start), philo->id);
}

void	eat(t_philo *philo)
{
	if (philo->data->philo_died)
		return ;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock (philo->right_fork);
		printf ("%zd Philo %d picked right fork\n", get_current_time (philo->data->start), philo->id);
		pthread_mutex_lock (philo->left_fork);
		printf ("%zd Philo %d picked left fork\n", get_current_time (philo -> data -> start), philo->id);
	}
	else
	{
		pthread_mutex_lock (philo->left_fork);
		printf ("%zd Philo %d picked left fork\n", get_current_time (philo->data->start), philo->id);
		pthread_mutex_lock (philo->right_fork);
		printf ("%zd Philo %d picked right fork\n", get_current_time (philo->data->start), philo->id);
	}
	pthread_mutex_lock(&philo->data->organizer);
	printf("%zd Philo %d is eating\n", get_current_time (philo->data->start), philo->id);
	philo->last_time_eaten = get_current_time (philo->data->start);
	philo->num_times_eaten ++ ;
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
