/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 08:02:29 by akharkho          #+#    #+#             */
/*   Updated: 2025/04/02 15:35:51 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(char *msg, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->msg);
	if (!death_flag(0, philo->data))
		printf("\033[0;32m%zd\033[0m \033[0;36m%d\033[0m \033[0;33m%s\033[0m\n",
			get_time() - philo->data->start, philo->id, msg);
	pthread_mutex_unlock(&philo->data->msg);
}

void	think(t_philo *philo)
{
	print_msg("is thinking", philo);
}

void	eat(t_philo *philo)
{
	if (philo->num_times_eaten == philo->data->max_num_to_eat)
		return ;
	if (philo->id % 2 == 0)
		usleep(philo->data->time_to_sleep);
	pthread_mutex_lock (philo->left_fork);
	print_msg("has taken a fork", philo);
	pthread_mutex_lock (philo->right_fork);
	print_msg("has taken a fork", philo);
	print_msg("is eating", philo);
	last_eat(philo, 1, 0, 0);
	ft_usleep(philo->data->time_to_eat, philo->data);
	last_eat(philo, 2, 0, 0);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_sleeping(t_philo *philo)
{
	print_msg("is sleeping", philo);
	ft_usleep(philo->data->time_to_sleep, philo->data);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->num_of_philos == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_msg("has taken a fork", philo);
		usleep(philo->data->time_to_die);
		pthread_mutex_unlock(philo->left_fork);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(10);
	while (!death_flag(0, philo->data))
	{
		eat(philo);
		philo_sleeping(philo);
		think(philo);
	}
	return (NULL);
}
