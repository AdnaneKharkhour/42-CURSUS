/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 08:02:32 by akharkho          #+#    #+#             */
/*   Updated: 2025/04/06 16:02:06 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	death_flag(int died, t_data *data)
{
	int	rs;

	rs = 0;
	pthread_mutex_lock(&data->organizer);
	if (died)
	{
		data->philo_died = 1;
		pthread_mutex_unlock(&data->organizer);
		return (0);
	}
	else
		rs = data->philo_died;
	pthread_mutex_unlock(&data->organizer);
	return (rs);
}

void	ft_usleep(long time, t_data *data)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
	{
		if (death_flag(0, data))
			break ;
		usleep(100);
	}
}

long	get_time(void)
{
	t_time	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	last_eat(t_philo *philo, int flag, time_t *time, int *num_eat)
{
	pthread_mutex_lock(&philo->data->eat);
	if (flag == 1)
		philo->last_time_eaten = get_time();
	else if (flag == 2)
		philo->num_times_eaten++;
	else
	{
		*time = philo->last_time_eaten;
		*num_eat = philo->num_times_eaten;
	}
	pthread_mutex_unlock(&philo->data->eat);
}

void	free_exit(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	if (philo)
		free(philo);
	while (i < data->num_of_philos)
	{
		pthread_detach(philo[i].thread);
		pthread_mutex_destroy(&data->forks[i++]);
	}
	free(data->forks);
	data->forks = NULL;
	pthread_mutex_destroy(&data->organizer);
	pthread_mutex_destroy(&data->msg);
	pthread_mutex_destroy(&data->eat);
}
