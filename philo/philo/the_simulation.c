/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:29:00 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/26 14:57:57 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *p_l)
{
	t_philo	*philo;

	philo = (t_philo *)p_l;
	if (philo->id % 2 == 0)
		ft_sleep(philo->data->time_to_eat);
	while (1)
	{
		pthread_mutex_lock(&(philo->fork));
		print_msg(philo, "has taken a fork");
		pthread_mutex_lock(&(philo->next->fork));
		print_msg(philo, "has taken a fork");
		print_msg(philo, "is eating");
		update_last_time_eat(philo);
		pthread_mutex_lock(&(philo->data->stop));
		if (philo->data->num_of_time_each_philo_must_eat != 0)
			philo->num_eat++;
		pthread_mutex_unlock(&(philo->data->stop));
		ft_sleep(philo->data->time_to_eat);
		pthread_mutex_unlock(&(philo->fork));
		pthread_mutex_unlock(&(philo->next->fork));
		print_msg(philo, "is sleeping");
		ft_sleep(philo->data->time_to_sleep);
		print_msg(philo, "is thinking");
	}
	return (NULL);
}

void	*routine_for_one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&(philo->fork));
	printf("%lld %d has taken a fork\n",
		get_time(1000) - philo->data->time, philo->id);
	ft_sleep(philo->data->time_to_die);
	printf("%lld %d died\n", get_time(1000) - philo->data->time, philo->id);
	return (NULL);
}

void	ft_check_death(t_philo *philo)
{
	while (philo)
	{
		pthread_mutex_lock(&(philo->data->stop));
		if (philo->num_eat != 0
			&& philo->num_eat > philo->data->num_of_time_each_philo_must_eat)
		{
			pthread_mutex_lock(&(philo->data->print));
			break ;
		}
		pthread_mutex_unlock(&(philo->data->stop));
		pthread_mutex_lock(&(philo->data->death));
		if (get_time(1000) - philo->last_time_eat >= philo->data->time_to_die)
		{
			print_msg(philo, "died");
			pthread_mutex_lock(&(philo->data->print));
			break ;
		}
		pthread_mutex_unlock(&(philo->data->death));
		philo = philo->next;
		usleep(200);
	}
}

void	simulation(t_philo *philo, t_data *data)
{
	int			num_philo;

	num_philo = philo->data->num_of_philo;
	if (num_philo == 1)
	{
		pthread_mutex_init(&(philo->fork), NULL);
		pthread_create(&(philo->threads),
			NULL, routine_for_one_philo, (void *)philo);
		pthread_join(philo->threads, NULL);
		pthread_mutex_destroy(&(philo->fork));
		return ;
	}
	pthread_mutex_init(&(data->death), NULL);
	pthread_mutex_init(&(data->print), NULL);
	pthread_mutex_init(&(data->stop), NULL);
	while (num_philo > 0)
	{
		pthread_mutex_init(&(philo->fork), NULL);
		pthread_create(&(philo->threads), NULL, routine, (void *)philo);
		pthread_detach(philo->threads);
		philo = philo->next;
		num_philo--;
	}
	ft_check_death(philo);
	destroy_mutex(philo);
}
