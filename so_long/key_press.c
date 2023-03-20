/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:23:07 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/18 21:24:28 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_up(t_var *var)
{
	char	*sc;	

	if (is_a_exit(var->width, var->height - 60, var) == 0
		|| (is_a_exit(var->width, var->height - 60, var) == 1
			&& var->number_of_coll == 0))
	{
		var->score++;
		sc = itoa(var->score);
		write(1, sc, 5);
		write(1, "\n", 1);
		free(sc);
		var->height -= 60;
		move_up(var);
	}
}

void	key_down(t_var *var)
{
	char	*sc;

	if (is_a_exit(var->width, var->height + 60, var) == 0
		|| (is_a_exit(var->width, var->height + 60, var) == 1
			&& var->number_of_coll == 0))
	{
		var->score++;
		sc = itoa(var->score);
		write(1, sc, 5);
		write(1, "\n", 1);
		free(sc);
		var->height += 60;
		move_down(var);
	}
}

void	key_right(t_var *var)
{
	char	*sc;

	if (is_a_exit(var->width + 60, var->height, var) == 0
		|| (is_a_exit(var->width + 60, var->height, var) == 1
			&& var->number_of_coll == 0))
	{
		var->score++;
		sc = itoa(var->score);
		write(1, sc, 5);
		write(1, "\n", 1);
		free(sc);
		var->width += 60;
		move_right(var);
	}
}

void	key_left(t_var *var)
{
	char	*sc;	

	if (is_a_exit(var->width - 60, var->height, var) == 0
		|| (is_a_exit(var->width - 60, var->height, var) == 1
			&& var->number_of_coll == 0))
	{
		var->score++;
		sc = itoa(var->score);
		write(1, sc, 5);
		write(1, "\n", 1);
		free(sc);
		var->width -= 60;
		move_left(var);
	}
}
