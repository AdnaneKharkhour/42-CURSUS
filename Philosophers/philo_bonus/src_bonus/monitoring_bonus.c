/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:51:41 by akharkho          #+#    #+#             */
/*   Updated: 2025/04/06 16:18:10 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static void	check_death(t_philo *philo, time_t time, int eat_num)
{
	if (get_time() - 
		time >= philo->data->time_to_die)
	{
		death_flag(1, philo->data);
		sem_wait(philo->data->msg);
		if (eat_num != philo->data->max_num_to_eat
			|| philo->data->max_num_to_eat == 1)
			printf("\033[0;31m%zd %d died \033[0m\n", get_time()
				- philo->data->start, philo->id);
		exit(1);
	}
}

void	*monitor(void *arg)
{
	t_philo	*philo;
	time_t	time;
	int		eat_num;

	philo = (t_philo *)arg;
	while (1)
	{
		last_eat(philo, 0, &time, &eat_num);
		check_death(philo, time, eat_num);
		if (philo->data->max_num_to_eat != -1 
			&& eat_num == philo->data->max_num_to_eat 
			&& philo->id == philo->data->num_of_philos)
			exit(1);
		usleep(500);
	}
	return (NULL);
}
