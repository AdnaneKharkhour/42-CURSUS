/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:43:01 by akharkho          #+#    #+#             */
/*   Updated: 2025/04/02 19:40:52 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>
# include <signal.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <sys/time.h>

typedef struct timeval	t_time;

typedef struct s_data
{
	int			num_of_philos;
	int			max_num_to_eat;
	int			philo_died;
	time_t		time_to_sleep;
	time_t		time_to_eat;
	time_t		time_to_die;
	time_t		start;
	sem_t		*forks;
	sem_t		*organizer;
	sem_t		*msg;
	sem_t		*eat;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				pid;
	int				num_times_eaten;
	time_t			last_time_eaten;
	t_data			*data;
}	t_philo;

// utils dir
int		ft_isdigit(int n);
long	ft_atoi(const char *str);
// init_struct.c
void	init_philo(t_data *data, t_philo *philo);
void	init_data(char **argv, int argc, t_data *data);
int		create_and_join_threads(t_data data, t_philo *philo);
int		check_args(t_data *data, int argc);
// actions.c
void	print_msg(char *msg, t_philo *philo);
void	think(t_philo *philo);
void	eat(t_philo *philo);
void	philo_sleeping(t_philo *philo);
void	routine(t_philo *philo);
// monitoring.c
void	*monitor(void *arg);
// utils.c
int		death_flag(int died, t_data *data);
void	ft_usleep(long time, t_data *data);
long	get_time(void);
void	last_eat(t_philo *philo, int flag, time_t *time, int *num_eat);
void	clean(t_data *data);
#endif