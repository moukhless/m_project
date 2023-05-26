/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:54:40 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/26 16:07:42 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_one_philo(t_philo *philo)
{
	print_msg(philo, "has taken a fork");
	ft_sleep(philo->data->time_to_die, philo);
	print_msg(philo, "died");
	exit(0);
}

void	routine(t_philo *philo, t_data *data)
{
	if (data->num_of_philo == 1)
		routine_one_philo(philo);
	while (1)
	{
		sem_wait(data->forks);
		sem_wait(data->forks);
		print_msg(philo, "has taken a fork");
		print_msg(philo, "has taken a fork");
		print_msg(philo, "is eating");
		ft_check_death(philo);
		philo->last_time_eat = get_time(1000);
		ft_sleep(philo->data->time_to_eat, philo);
		if (philo->data->num_of_time_each_philo_must_eat != 0)
			philo->num_eat++;
		sem_post(data->forks);
		sem_post(data->forks);
		ft_check_num_eat(philo);
		print_msg(philo, "is sleeping");
		ft_sleep(philo->data->time_to_sleep, philo);
		print_msg(philo, "is thinking");
		if (data->time_to_eat > data->time_to_sleep)
			ft_sleep(data->time_to_eat - data->time_to_sleep, philo);
	}
}

void	creat_process(t_philo *philo, t_data *data)
{
	int		num_philo;
	t_philo	*head;

	head = philo;
	num_philo = data->num_of_philo;
	while (num_philo > 0)
	{
		philo->child_id = fork();
		if (philo->child_id == -1)
		{
			ft_kill_process(head, data->num_of_philo - num_philo);
			exit (1);
		}
		if (philo->child_id == 0)
			routine(philo, data);
		philo = philo->next;
		num_philo--;
	}
}

void	simulation(t_philo *philo, t_data *data)
{
	int	num_philo;

	num_philo = data->num_of_philo;
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/wait");
	data->forks = sem_open("/forks", O_CREAT, 0777, num_philo);
	if (data->forks == SEM_FAILED)
		exit (1);
	data->print = sem_open("/print", O_CREAT, 0777, 1);
	if (data->print == SEM_FAILED)
		exit (1);
	data->wait = sem_open("/wait", O_CREAT, 0777, 0);
	if (data->wait == SEM_FAILED)
		exit (1);
	creat_process(philo, data);
	ft_wait_child_process(philo, data);
	sem_close(data->print);
	sem_close(data->forks);
	sem_close(data->wait);
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/wait");
	free(philo->data);
	clean_philo(&philo);
}

void	ft_wait_child_process(t_philo *philo, t_data *data)
{
	int	num_philo;

	num_philo = data->num_of_philo;
	if (data->num_of_time_each_philo_must_eat == 0)
	{
		waitpid(-1, NULL, 0);
		ft_kill_process(philo, data->num_of_philo);
	}
	else
	{
		while (num_philo > 0)
		{
			sem_wait(data->wait);
			num_philo--;
		}
		ft_kill_process(philo, data->num_of_philo);
	}
}
