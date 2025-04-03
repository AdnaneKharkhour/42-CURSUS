/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:51:41 by akharkho          #+#    #+#             */
/*   Updated: 2025/04/03 18:51:06 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static void	check_death(t_philo *philo, time_t *time, int *eat_num)
{
	sem_wait(philo->data->eat);
	*time = philo->last_time_eaten;
	*eat_num = philo->num_times_eaten;
	sem_post(philo->data->eat);
	if (get_time() - 
		*time >= philo->data->time_to_die 
		&& *eat_num != philo->data->max_num_to_eat)
	{
		death_flag(1, philo->data);
		sem_wait(philo->data->msg);
		printf("\033[0;31m%zd %d died \033[0m\n", get_time()
			- philo->data->start, philo->id);
		exit (EXIT_FAILURE);
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
		check_death(philo, &time, &eat_num);
		if (philo->data->max_num_to_eat != -1 
			&& eat_num == philo->data->max_num_to_eat)
			exit (EXIT_SUCCESS);
		ft_usleep(500);
	}
	return (NULL);
}
