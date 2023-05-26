/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_man.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:31:35 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/25 16:12:49 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(char **argv)
{
	int	i;
	int	num;

	i = 1;
	while (argv[i])
	{
		if (is_digit(argv[i]) == 1)
			return (1);
		num = atoi(argv[i]);
		if (num == 0)
			return (1);
		i++;
	}
	return (0);
}

long long	get_time(int i)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_usec / i + tv.tv_sec * i);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_data	*data;

	if (argc == 5 || argc == 6)
	{
		if (check_arg(argv) == 1)
			return (1);
		data = get_data(argv);
		philo = creat_philos(data);
		simulation(philo, data);
		return (0);
	}
	return (1);
}
