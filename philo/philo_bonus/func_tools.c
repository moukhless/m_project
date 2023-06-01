/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:55:16 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/29 20:49:01 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(unsigned long c_time, t_philo *philo)
{
	unsigned long	t_time;

	t_time = get_time(1000);
	while (get_time(1000) - t_time < c_time)
	{
		ft_check_death(philo);
		usleep(100);
	}
}

void	print_msg(t_philo *philo, char *str)
{
	sem_wait(philo->data->print);
	printf("%lu %d %s\n", get_time(1000) - philo->data->time, philo->id, str);
	sem_post(philo->data->print);
}

void	ft_check_death(t_philo *philo)
{
	int	num_philo;

	num_philo = philo->data->num_of_philo;
	if (get_time(1000) - philo->last_time_eat >= philo->data->time_to_die)
	{
		sem_wait(philo->data->print);
		printf("%lu %d died\n",
			get_time(1000) - philo->data->time, philo->id);
		if (philo->data->num_of_time_each_philo_must_eat != 0)
		{
			while (num_philo > 0)
			{
				sem_post(philo->data->wait);
				num_philo--;
			}
		}
		exit(1);
	}
}

void	ft_check_num_eat(t_philo *philo)
{
	if (philo->num_eat != 0
		&& philo->num_eat == philo->data->num_of_time_each_philo_must_eat)
	{
		sem_post(philo->data->wait);
	}
}

void	ft_kill_process(t_philo *philo, int num_of_process)
{
	while (num_of_process > 0)
	{
		kill(philo->child_id, SIGKILL);
		philo = philo->next;
		num_of_process--;
	}
}
