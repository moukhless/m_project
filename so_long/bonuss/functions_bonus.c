/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:43:39 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/04 00:53:13 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void free_all_and_exit_bonus(t_var *var)
{
	int i;
	
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

int width_wind_bonus(char *string)
{
	int i;

	i = 0;
	while (string[i])
		i++;
	return (i - 1);
}

void height_width_wind_bonus(t_var *var, int fd)
{
	char *string;
	
	string = get_next_line(fd);
	if (string)
		var->width_win = width_wind_bonus(string) * 60;
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

void check_map_walls_bonus(t_var *var)
{
	int i;
	int j;

	i = 0;
	while (var->str[i])
	{
		j = 0;
		while (var->str[i][j])
		{
			if ((var->str[0][j] != '1' && j != var->width_win / 60)
				|| (var->str[(var->height_win / 60) - 1][j] != '1' && j != var->width_win / 60)
				|| var->str[i][0] != '1' || var->str[i][(var->width_win / 60) - 1] != '1')
			{
				write(2, "Error\n", 6);
				write(2, "Your map not closed/surrounded by walls.\n", 41);
				free_all_and_exit_bonus(var);
			}
			j++;
		}
		i++;
	}
}

void check_map_bonus(t_var *var)
{
	if (var->number_of_player > 1 || var->number_of_exit > 1 || var->height_win >= var->width_win
		|| var->number_of_player == 0 || var->number_of_exit == 0 || var->number_of_coll == 0)
	{
		write(2, "Error\n", 6);
		if (var->height_win >= var->width_win)
			write(2, "Your map must be rectangular.\n", 30);
		else if (var->number_of_player == 0 || var->number_of_exit == 0 || var->number_of_coll == 0)
			write(2, "Your map must contain 1 exit, at least 1 collectible, and 1 starting position.\n", 79);
		else
			write(2, "Duplicates characters (exit/start).\n", 36);
		free_all_and_exit_bonus(var);
	}
	check_map_walls_bonus(var);
}
