/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:43:01 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/23 08:05:59 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct timeval	t_time;

typedef struct s_data
{
	int				num_of_philos;
	time_t			time_to_sleep;
	time_t			time_to_eat;
	time_t			time_to_die;
	time_t			start;
	int				max_num_to_eat;
	int				philo_died;
	pthread_mutex_t	*forks;
	pthread_mutex_t	organizer;
	pthread_mutex_t	msg;
	pthread_mutex_t	eat;
	pthread_t		monitor_thread;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				num_times_eaten;
	time_t			last_time_eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	t_data			*data;
}	t_philo;

int		ft_isdigit(int n);
int		ft_atoi(const char *str);
void	*routine(void *arg);
long	get_time(void);
void	ft_usleep(long time, t_data *data);
int		free_exit(t_data *data, t_philo *philo);
int		create_and_join_threads(t_data data, t_philo *philo);
void	init_philo(t_data *data, t_philo *philo);
// actions.c
int		get_flag_value(int died, t_data *data);
void	think(t_philo *philo);
void	eat(t_philo *philo);
void	philo_sleeping(t_philo *philo);
void	last_eat(t_philo *philo, int flag, time_t *time, int *num_eat);
//monitoring.c
void	*monitor(void *arg);
#endif