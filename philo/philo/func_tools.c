/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:13:19 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/30 20:17:29 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *philo, char *str)
{
	pthread_mutex_lock(&(philo->data->print));
	printf("%lu %d %s\n", get_time(1000) - philo->data->time, philo->id, str);
	pthread_mutex_unlock(&(philo->data->print));
}

void	destroy_mutex(t_philo *philo)
{
	int	num_philo;

	num_philo = philo->data->num_of_philo;
	while (num_philo > 0)
	{
		pthread_mutex_destroy(&(philo->fork));
		philo = philo->next;
		num_philo--;
	}
	pthread_mutex_destroy(&(philo->data->death));
	pthread_mutex_destroy(&(philo->data->print));
	pthread_mutex_destroy(&(philo->data->stop));
}

void	ft_sleep(unsigned long c_time)
{
	unsigned long	t_time;

	t_time = get_time(1000);
	while (get_time(1000) - t_time < c_time)
	{
		usleep(500);
	}
}

void	update_last_time_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->death));
	philo->last_time_eat = get_time(1000);
	pthread_mutex_unlock(&(philo->data->death));
}
