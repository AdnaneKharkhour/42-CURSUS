/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:51:41 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/17 10:52:56 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_dead_or_finished(t_philo *philo, int *all_finished, int i)
{
	if (philo[i].last_time_eaten)
	{
		if (get_current_time() - 
			philo[i].last_time_eaten > philo->data->time_to_die)
		{
			printf("Philo %d died\n", philo[i].id);
			philo->data->philo_died = 1;
			return (1);
		}
	}
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
			philo->data->philo_died = 1;
			printf("finished eating");
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
