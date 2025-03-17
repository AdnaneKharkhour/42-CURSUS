/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 08:02:29 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/17 11:20:53 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(int id)
{
	printf("Philo %d is thinking\n", id);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->organizer);
	pthread_mutex_lock(philo->left_fork);
	printf("Philo %d picked left fork\n", philo->id);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_unlock(&philo->data->organizer);
	printf("Philo %d picked right fork\n", philo->id);
	printf("Philo %d is eating\n", philo->id);
	philo->last_time_eaten = get_current_time();
	philo->num_times_eaten++;
	usleep(philo->data->time_to_eat * 500);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_sleeping(t_philo *philo)
{
	printf("Philo %d is sleeping\n", philo->id);
	usleep(philo->data->time_to_sleep * 300);
}
