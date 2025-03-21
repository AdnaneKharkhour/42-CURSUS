/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 08:02:29 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/21 10:55:24 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(char *msg, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->msg);
	if (!philo->data->philo_died)
		printf("\033[0;32m%zd\033[0m \033[0;36m%d\033[0m \033[0;33m%s\033[0m\n",
			get_time() - philo->data->start, philo->id, msg);
	pthread_mutex_unlock(&philo->data->msg);
}

void	think(t_philo *philo)
{
	// printf("%zd Philo %d is thinking\n", get_time() - philo->data->start, philo->id);
	print_msg("is thinking", philo);
}

void	eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_msg("has taken a fork", philo);
		pthread_mutex_lock(philo->left_fork);
		// printf ("%zd Philo %d picked right fork\n", get_time() - philo->data->start, philo->id);
		// printf ("%zd Philo %d picked left fork\n", get_time() - philo->data->start, philo->id);
		print_msg("has taken a fork", philo);
	}
	else
	{
		pthread_mutex_lock (philo->left_fork);
		print_msg("has taken a fork", philo);
		pthread_mutex_lock (philo->right_fork);
		// printf ("%zd Philo %d picked left fork\n", get_time() - philo->data->start, philo->id);
		// printf ("%zd Philo %d picked right fork\n", get_time() - philo->data->start, philo->id);
		print_msg("has taken a fork", philo);
	}
	pthread_mutex_lock(&philo->data->eat);
	print_msg("is eating", philo);
	ft_usleep(philo->data->time_to_eat, philo->data);
	philo->last_time_eaten = get_time();
	// printf("%zd Philo %d is eating\n", get_time() - philo->data->start, philo->id);
	philo->num_times_eaten++ ;
	pthread_mutex_unlock(&philo->data->eat);
	pthread_mutex_unlock(&philo->data->organizer);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_sleeping(t_philo *philo)
{
	// printf("%zd Philo %d is sleeping\n", get_time() - philo->data->start, philo->id);
	print_msg("is sleeping", philo);
	ft_usleep(philo->data->time_to_sleep, philo->data);
}
