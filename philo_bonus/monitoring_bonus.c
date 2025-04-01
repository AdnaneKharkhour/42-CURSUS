/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:51:41 by akharkho          #+#    #+#             */
/*   Updated: 2025/04/01 16:49:20 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	check_dead_or_finished(t_philo *philo, int *all_finished)
{
	long	time;
	int		eat_num;

	last_eat(philo, 0, &time, &eat_num);
	if (get_time() - 
		time >= philo->data->time_to_die)
	{
		death_flag(1, philo->data);
		sem_wait(philo->data->msg);
		printf("\033[0;31m%zd %d died \033[0m\n", get_time()
			- philo->data->start, philo->id);
		return (1);
	}
	if (philo->data->max_num_to_eat != -1 
		&& eat_num < philo->data->max_num_to_eat)
		*all_finished = 0;
	return (0);
}

void	*monitor(void *arg)
{
	t_philo	*philo;
	int		all_finished;

	philo = (t_philo *)arg;
	while (1)
	{
		all_finished = 1;
		if (check_dead_or_finished(philo, &all_finished))
			exit(EXIT_FAILURE);
		if (all_finished && philo->data->max_num_to_eat != -1)
		{
			ft_usleep(philo->data->time_to_eat * 10, philo->data);
			sem_wait(philo->data->organizer);
			philo->data->philo_died = 1;
			sem_post(philo->data->organizer);
			exit (EXIT_SUCCESS);
		}
		usleep(500);
	}
	return (NULL);
}
