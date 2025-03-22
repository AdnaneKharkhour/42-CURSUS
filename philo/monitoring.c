/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:51:41 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/22 14:35:54 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_dead_or_finished(t_philo *philo, int *all_finished, int i)
{
	pthread_mutex_lock(&philo->data->eat);
	if (philo[i].last_time_eaten)
	{
		if (get_time() - 
			philo[i].last_time_eaten >= philo->data->time_to_die)
		{
			pthread_mutex_lock(&philo->data->organizer);
			philo->data->philo_died = 1;
			pthread_mutex_unlock(&philo->data->organizer);
			pthread_mutex_unlock(&philo->data->eat);
			printf("\033[0;31m%zd %d died \033[0m\n", get_time()
				- philo[i].data->start, philo[i].id);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->data->eat);
	if (philo->data->max_num_to_eat != -1 
		&& philo[i].num_times_eaten < philo->data->max_num_to_eat)
		*all_finished = 0;
	return (0);
}

void	*monitor(void *arg)
{
	t_philo	*philo;
	int		i;
	int		all_finished;

	philo = (t_philo *)arg;
	while (1)
	{
		i = 0;
		all_finished = 1;
		while (i < philo->data->num_of_philos)
		{
			if (check_dead_or_finished(philo, &all_finished, i))
				return (NULL);
			i++;
		}
		if (all_finished && philo->data->max_num_to_eat != -1)
		{
			pthread_mutex_lock(&philo->data->organizer);
			philo->data->philo_died = 1;
			pthread_mutex_unlock(&philo->data->organizer);
			printf("finished eating");
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
