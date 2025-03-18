/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:51:41 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/18 15:52:27 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_dead_or_finished(t_philo *philo, int *all_finished, int i)
{
	pthread_mutex_lock(&philo->data->organizer);
	if (philo[i].last_time_eaten)
	{
		if (get_current_time() - 
			philo[i].last_time_eaten > philo->data->time_to_die + 1)
		{
			printf("Philo %d died\n", philo[i].id);
			philo->data->philo_died = 1;
			pthread_mutex_unlock(&philo->data->organizer);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->data->organizer);
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
			printf("finished eating");
			pthread_mutex_unlock(&philo->data->organizer);
			return (NULL);
		}
		ft_usleep(1000, philo->data);
	}
	return (NULL);
}
