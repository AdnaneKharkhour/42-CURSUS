/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 08:02:29 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/27 15:38:19 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_msg(char *msg, t_philo *philo)
{
	sem_wait(&philo->data->msg);
	if (!death_flag(0, philo->data))
		printf("\033[0;32m%zd\033[0m \033[0;36m%d\033[0m \033[0;33m%s\033[0m\n",
			get_time() - philo->data->start, philo->id, msg);
	sem_post(&philo->data->msg);
}

void	think(t_philo *philo)
{
	print_msg("is thinking", philo);
}

void	eat(t_philo *philo)
{
	if (philo->num_times_eaten == philo->data->max_num_to_eat)
		exit(EXIT_SUCCESS) ;
	// if (philo->id % 2 == 0)
	// 	usleep(philo->data->time_to_sleep);
	sem_wait (philo->data->forks);
	print_msg("has taken a fork", philo);
	sem_wait (philo->data->forks);
	print_msg("has taken a fork", philo);
	print_msg("is eating", philo);
	ft_usleep(philo->data->time_to_eat, philo->data);
	last_eat(philo, 1, 0, 0);
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
	// if (philo->data->num_of_philos == 1)
	// {
	// 	sem_wait(philo->left_fork);
	// 	print_msg("has taken a fork", philo);
	// 	usleep(philo->data->time_to_die);
	// 	sem_post(philo->left_fork);
	// 	return (NULL);
	// }
	// if (philo->id % 2 == 0)
	// 	usleep(10);
	while (!death_flag(0, philo->data))
	{
		eat(philo);
		philo_sleeping(philo);
		think(philo);
	}
}
