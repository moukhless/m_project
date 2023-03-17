/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:53:47 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/17 13:08:07 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key_press(int keycode, t_var *var)
{
	if ((keycode == 13 || keycode == 126)
		&& is_a_wall(var->width, var->height - 60, var) == 0)
		key_up(var);
	else if ((keycode == 1 || keycode == 125)
		&& is_a_wall(var->width, var->height + 60, var) == 0)
		key_down(var);
	else if ((keycode == 2 || keycode == 124)
		&& is_a_wall(var->width + 60, var->height, var) == 0)
		key_right(var);
	else if ((keycode == 0 || keycode == 123)
		&& is_a_wall(var->width - 60, var->height, var) == 0)
		key_left(var);
	else if (keycode == 53)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		free_all_and_exit(var);
	}
	if (is_a_collectible(var->width, var->height, var) == 1)
		var->number_of_coll--;
	if (is_a_exit(var->width, var->height, var) == 1 & var->number_of_coll == 0)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		free_all_and_exit(var);
	}
	return (0);
}

void	fill_map_in_matrix(t_var *var, int fd, char **argv)
{
	var->number_of_coll = 0;
	var->number_of_player = 0;
	var->number_of_exit = 0;
	height_width_wind(var, fd);
	fd = open(argv[1], O_RDONLY);
	var->str = (char **)malloc(sizeof(char *) * ((var->height_win / 60)) + 1);
	if (!var->str)
	{
		free(var);
		exit (0);
	}
	fill_map_in_matrix_next(var, fd);
	check_map(var);
	check_map_is_playable(var);
}

void	fill_map_in_matrix_next(t_var *var, int fd)
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

int	destroy_notify_handler(t_var *var)
{
	free_all_and_exit(var);
	return (0);
}

void	protect_img(t_var *var)
{
	if (!var->img_ptr_wall || !var->img_ptr_ground || !var->img_ptr_coll
		|| !var->img_ptr_exit || !var->img_ptr_player)
	{
		perror("");
		write(2, "Can't access to image.\n", 24);
		free_all_and_exit(var);
	}
	if (!var->mlx_ptr || !var->win_ptr)
	{
		perror("");
		free_all_and_exit(var);
	}
}
