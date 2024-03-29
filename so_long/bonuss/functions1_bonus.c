/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:48:56 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/21 11:21:41 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_map_in_matrix_bonus(t_var *var, int fd, char **argv)
{
	var->number_of_coll = 0;
	var->number_of_player = 0;
	var->number_of_exit = 0;
	height_width_wind_bonus(var, fd);
	if (var->height_win > 2880 || var->width_win > 5120)
	{
		write(2, "ERROR\n", 6);
		write(2, "Bad resolution.\n", 16);
		free(var);
		exit (0);
	}
	fd = open(argv[1], O_RDONLY);
	var->str = (char **)malloc(sizeof(char *) * ((var->height_win / 60)) + 1);
	if (!var->str)
	{
		free(var);
		exit (0);
	}
	fill_map_in_matrix_next_bonus(var, fd);
	check_map_bonus(var);
	check_map_is_playable_bonus(var);
}

void	protect_img_bonus(t_var *var)
{
	if (!var->img_ptr_wall || !var->img_ptr_ground || !var->img_ptr_coll
		|| !var->img_ptr_exit || !var->img_ptr_player || !var->img_ptr_enemy)
	{
		write(2, "ERROR\n", 6);
		write(2, "Can't access to image.\n", 23);
		free_all_and_exit_bonus(var);
	}
	if (!var->mlx_ptr || !var->win_ptr)
	{
		write(2, "ERROR\n", 6);
		write(2, "Problem in alocation\n", 21);
		free_all_and_exit_bonus(var);
	}
}

void	fill_map_in_matrix_next_bonus(t_var *var, int fd)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->height_win / 60)
	{
		var->str[i] = get_next_line(fd);
		j = 0;
		while (j < var->width_win / 60)
		{
			if (var->str[i][j] == 'C')
				var->number_of_coll++;
			if (var->str[i][j] == 'P')
				var->number_of_player++;
			if (var->str[i][j] == 'E')
				var->number_of_exit++;
			j++;
		}
		i++;
	}
	var->str[i] = NULL;
}

int	handle_key_press_bonus(int keycode, t_var *var)
{
	static int	m_up;
	static int	m_down;
	static int	m_right;
	static int	m_left;

	if (keycode == 13 || keycode == 126)
		animation_player_up(var, &m_up);
	else if (keycode == 1 || keycode == 125)
		animation_player_down(var, &m_down);
	else if (keycode == 2 || keycode == 124)
		animation_player_right(var, &m_right);
	else if (keycode == 0 || keycode == 123)
		animation_player_left(var, &m_left);
	else if (keycode == 53)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		free_all_and_exit_bonus(var);
	}
	return (0);
}

int	destroy_notify_handler(t_var *var)
{
	free_all_and_exit_bonus(var);
	return (0);
}
