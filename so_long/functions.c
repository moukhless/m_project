/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:52:01 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/21 11:14:18 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all_and_exit(t_var *var)
{
	int	i;

	i = 0;
	while (var->str[i])
	{
		free(var->str[i]);
		i++;
	}
	free(var->str[i]);
	free(var->str);
	free(var);
	exit(0);
}

int	width_wind(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i - 1);
}

void	height_width_wind(t_var *var, int fd)
{
	char	*string;

	string = get_next_line(fd);
	if (string)
		var->width_win = width_wind(string) * 60;
	else
	{
		write(2, "Error\n", 6);
		write(2, "Can't access to map.\n", 21);
		free(var);
		exit(0);
	}
	var->height_win = 0;
	while (string)
	{
		free(string);
		string = get_next_line(fd);
		var->height_win++;
	}
	var->height_win = var->height_win * 60;
	close(fd);
}

void	check_map_walls(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->str[i])
	{
		j = 0;
		while (var->str[i][j])
		{
			if ((var->str[0][j] != '1' && j != var->width_win / 60)
				|| (var->str[(var->height_win / 60) - 1][j] != '1'
				&& j != var->width_win / 60)
				|| var->str[i][0] != '1'
				|| var->str[i][(var->width_win / 60) - 1] != '1')
			{
				write(2, "Error\n", 6);
				write(2, "Your map not closed/surrounded by walls.\n", 41);
				free_all_and_exit(var);
			}
			j++;
		}
		i++;
	}
}

void	check_map(t_var *var)
{
	if (var->number_of_player > 1 || var->number_of_exit > 1
		|| var->number_of_player == 0 || var->number_of_exit == 0
		|| var->number_of_coll == 0)
	{
		write(2, "Error\n", 6);
		if (var->number_of_player == 0 || var->number_of_exit == 0
			|| var->number_of_coll == 0)
			write(2, "You missed caracter\n", 20);
		else
			write(2, "Duplicates characters (exit/start).\n", 36);
		free_all_and_exit(var);
	}
	check_map_walls(var);
}
