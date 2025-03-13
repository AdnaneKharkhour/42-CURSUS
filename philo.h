/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:43:01 by akharkho          #+#    #+#             */
/*   Updated: 2025/03/13 11:47:56 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				num_times_eaten;
	int				last_time_eaten;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	pthread_t		thread;
}	t_philo;

typedef struct s_data
{
	int				num_of_philos;
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_die;
	int				max_num_to_eat;
	t_philo			*philo;
	pthread_mutex_t	*forks;
}	t_data;

#endif