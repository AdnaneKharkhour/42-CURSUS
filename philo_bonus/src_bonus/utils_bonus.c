/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 08:02:32 by akharkho          #+#    #+#             */
/*   Updated: 2025/04/03 18:33:17 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	death_flag(int flag, t_data *data)
{
	int	rs;

	rs = 0;
	sem_wait(data->organizer);
	if (flag == 1)
	{
		data->philo_died = 1;
		sem_post(data->organizer);
		return (0);
	}
	else if (flag == 2)
	{
		data->all_finished++;
		sem_post(data->organizer);
		return (0);
	}
	else
		rs = data->philo_died;
	sem_post(data->organizer);
	return (rs);
}

void	ft_usleep(long time)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

long	get_time(void)
{
	t_time	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	last_eat(t_philo *philo, int flag, time_t *time, int *num_eat)
{
	sem_wait(philo->data->eat);
	if (flag == 1)
		philo->last_time_eaten = get_time();
	else if (flag == 2)
		philo->num_times_eaten++;
	else
	{
		*time = philo->last_time_eaten;
		*num_eat = philo->num_times_eaten;
	}
	sem_post(philo->data->eat);
}

void	clean(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->organizer);
	sem_close(data->msg);
	sem_close(data->eat);
	sem_unlink("/forks");
	sem_unlink("/organizer");
	sem_unlink("/msg");
	sem_unlink("/eat");
}
