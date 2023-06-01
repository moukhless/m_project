/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:31:56 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/31 15:16:51 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data
{
	int						num_of_philo;
	unsigned long			time_to_die;
	unsigned long			time_to_eat;
	unsigned long			time_to_sleep;
	int						num_of_time_each_philo_must_eat;
	unsigned long			time;
	pthread_mutex_t			print;
	pthread_mutex_t			stop;
	pthread_mutex_t			death;
}	t_data;

typedef struct s_philo
{
	int					id;
	pthread_mutex_t		fork;
	pthread_t			threads;
	int					num_eat;
	unsigned long		last_time_eat;
	struct s_philo		*next;
	t_data				*data;
}	t_philo;

int							is_digit(char *str);
int							check_arg(char **argv);
int							ft_strcmp(char *s1, char *s2);
unsigned long				ft_atoi(char *str);
int							ft_isdigit(int c);
t_philo						*new_philo(int id, t_data *data);
void						add_philo(t_philo **list_philo,
								t_philo *new_philo, int i);
t_philo						*creat_philos(t_data *data);
void						simulation(t_philo *philo, t_data *data);
void						*routine(void *philo);
unsigned long				get_time(int i);
void						destroy_mutex(t_philo *philo);
void						ft_sleep(unsigned long c_time);
void						update_last_time_eat(t_philo *philo);
void						print_msg(t_philo *philo, char *str);
t_data						*get_data(char **argv);
void						*routine_for_one_philo(void *arg);
void						ft_check_death(t_philo *philo);
void						clean_philo(t_philo **philo);

#endif