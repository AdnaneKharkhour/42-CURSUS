/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharkho <akharkho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:54:22 by akharkho          #+#    #+#             */
/*   Updated: 2025/04/03 18:04:24 by akharkho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	wait_pids(t_data *data, t_philo	*philo)
{
	int	i;
	int	status;
	int	dead;

	dead = 0;
	while (!dead && data->all_finished < data->num_of_philos)
	{
		if (waitpid(-1, &status, 0) > 0)
		{
			if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
			{
				dead = 1;
				i = 0;
				while (i < data->num_of_philos)
					kill(philo[i++].pid, SIGKILL);
			}
			else if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
			{
				death_flag(2, data);
				if (data->all_finished == data->num_of_philos)
					break ;
			}
		}
	}
	clean(data);
}

void	creat_semaphores(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/organizer");
	sem_unlink("/msg");
	sem_unlink("/eat");
	data->forks = sem_open("/forks", O_CREAT, 0644, data->num_of_philos);
	data->organizer = sem_open("/organizer", O_CREAT, 0644, 1);
	data->msg = sem_open("/msg", O_CREAT, 0644, 1);
	data->eat = sem_open("/eat", O_CREAT, 0644, 1);
	if (!data->forks || !data->organizer || !data->msg || !data->eat)
	{
		printf("Error:\n failed semopen");
		exit(EXIT_FAILURE);
	}
}

void	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	creat_semaphores(data);
	i = 0;
	while (i < data->num_of_philos)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].num_times_eaten = 0;
		philo[i].last_time_eaten = get_time();
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			routine(&philo[i]);
			exit(EXIT_SUCCESS);
		}
		else if (philo[i].pid < 0)
		{
			write(2, "Error: failed to fork\n", 23);
			clean(data);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	wait_pids(data, philo);
}

void	init_data(char **argv, int argc, t_data *data)
{
	data->num_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->max_num_to_eat = -1;
	data->philo_died = 0;
	data->all_finished = 0;
	data->start = get_time();
	if (argc == 6)
	{
		data->max_num_to_eat = ft_atoi(argv[5]);
	}
}

int	check_args(t_data *data, int argc)
{
	if (data->num_of_philos < 0 || data->time_to_die < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0)
	{
		printf("Error:\n invalid value in args");
		return (1);
	}
	if (argc == 6)
	{
		if (data->max_num_to_eat < 0)
		{
			printf("Error:\n invalid value in args");
			return (1);
		}
	}
	return (0);
}
