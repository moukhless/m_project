/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:29:04 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/03 23:41:31 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void key_up_bonus(t_var *var)
{
	if ((is_a_exit_bonus(var->x, var->y - 1, var) == 0 
		|| (is_a_exit_bonus(var->x, var->y - 1, var) == 1 && var->number_of_coll == 0)) 
		&& is_a_wall_bonus(var->x, var->y - 1, var) == 0) 
	{
		var->y -= 1;
		move_up_bonus(var);
	}
}

void key_down_bonus(t_var *var)
{
	if ((is_a_exit_bonus(var->x, var->y + 1, var) == 0 
		|| (is_a_exit_bonus(var->x, var->y + 1, var) == 1 && var->number_of_coll == 0)) 
		&& is_a_wall_bonus(var->x, var->y + 1, var) == 0) 
	{
		var->y += 1;
		move_down_bonus(var);
	}	
}

void key_right_bonus(t_var *var)
{	
	if ((is_a_exit_bonus(var->x + 1, var->y, var) == 0 
		|| (is_a_exit_bonus(var->x + 1, var->y, var) == 1 && var->number_of_coll == 0)) 
		&& is_a_wall_bonus(var->x + 1, var->y, var) == 0) 
	{
		var->x += 1;
		move_right_bonus(var);
	}
}

void key_left_bonus(t_var *var)
{
	if ((is_a_exit_bonus(var->x - 1, var->y, var) == 0 
		|| (is_a_exit_bonus(var->x - 1, var->y, var) == 1 && var->number_of_coll == 0)) 
		&& is_a_wall_bonus(var->x - 1, var->y, var) == 0) 
	{
		var->x -= 1;
		move_left_bonus(var);
	}
}