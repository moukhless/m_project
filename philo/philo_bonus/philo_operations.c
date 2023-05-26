/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:54:13 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/25 23:18:40 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*new_philo(int id, t_data *data)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->data = data;
	philo->id = id;
	philo->num_eat = 0;
	philo->last_time_eat = data->time;
	philo->next = NULL;
	return (philo);
}

void	add_philo(t_philo **list_philo, t_philo *new_philo, int i)
{
	t_philo	*head;
	t_philo	*p;

	if (!list_philo)
	{
		*list_philo = new_philo;
		return ;
	}
	p = *list_philo;
	head = *list_philo;
	while (i - 1 > 0)
	{
		p = p->next;
		i--;
	}
	p->next = new_philo;
	new_philo->next = head;
}

t_philo	*creat_philos(t_data *data)
{
	t_philo		*philo;
	int			num_philo;
	static int	i;
	int			id;

	i = 1;
	id = 1;
	num_philo = data->num_of_philo;
	philo = new_philo(id, data);
	while (num_philo - 1 > 0)
	{
		id++;
		add_philo(&philo, new_philo(id, data), i);
		i++;
		num_philo--;
	}
	return (philo);
}

t_data	*get_data(char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->time = get_time(1000);
	if (argv[5])
		data->num_of_time_each_philo_must_eat = ft_atoi(argv[5]);
	else
		data->num_of_time_each_philo_must_eat = 0;
	return (data);
}

void	clean_philo(t_philo **philo)
{
	int		num_philo;
	t_philo	*p;

	p = *philo;
	num_philo = (*philo)->data->num_of_philo;
	while (num_philo > 0)
	{
		p = (*philo)->next;
		free((*philo));
		*philo = p;
		num_philo--;
	}
}
