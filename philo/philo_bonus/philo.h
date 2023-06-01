/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:49:06 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/29 20:47:41 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>

typedef struct s_data
{
	int						num_of_philo;
	unsigned long			time_to_die;
	unsigned long			time_to_eat;
	unsigned long			time_to_sleep;
	int						num_of_time_each_philo_must_eat;
	unsigned long			time;
	sem_t					*forks;
	sem_t					*print;
	sem_t					*wait;
}	t_data;

typedef struct s_philo
{
	int					id;
	pid_t				child_id;
	int					num_eat;
	unsigned long		last_time_eat;
	struct s_philo		*next;
	t_data				*data;
	pthread_t			threads;
}	t_philo;

void					ft_sleep(unsigned long c_time, t_philo *philo);
int						is_digit(char *str);
int						ft_strcmp(char *s1, char *s2);
int						ft_isdigit(int c);
unsigned long			ft_atoi(char *str);
unsigned long			get_time(int i);
int						check_arg(char **argv);
t_philo					*new_philo(int id, t_data *data);
void					add_philo(t_philo **list_philo,
							t_philo *new_philo, int i);
t_philo					*creat_philos(t_data *data);
t_data					*get_data(char **argv);
void					print_msg(t_philo *philo, char *str);
void					simulation(t_philo *philo, t_data *data);
void					routine_one_philo(t_philo *philo);
void					creat_process(t_philo *philo, t_data *data);
void					ft_wait_child_process(t_philo *philo, t_data *data);
void					ft_check_num_eat(t_philo *philo);
void					ft_check_death(t_philo *philo);
void					ft_kill_process(t_philo *philo, int num_of_process);
void					clean_philo(t_philo **philo);

#endif