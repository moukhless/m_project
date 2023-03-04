/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 00:22:43 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/04 01:41:10 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void enemy_movement(t_var *var)
{
    static int count_up;
    static int count_down;
    static int count_right;
    static int count_left;
    int width_img;
    int height_img;
    
    if (is_a_collectible_bonus(var->x_enemy, var->y_enemy - 1, var) == 0 
        && is_a_exit_bonus(var->x_enemy, var->y_enemy, var) == 0
        && is_a_wall_bonus(var->x_enemy, var->y_enemy - 1, var) == 0
        && count_down == 0 && count_left == 0)
    {
        count_up++;
        count_down = 0;
        count_left = 0;
        count_right = 0;
        var->y_enemy -= 1;
        var->str[var->y_enemy][var->x_enemy] = 'M';
        var->str[var->y_enemy + 1][var->x_enemy] = '0';
        var->img_ptr_enemy = var->img_ptr_enemy = mlx_xpm_file_to_image(var->mlx_ptr, "textures/enemy_up.xpm", &width_img, &height_img);
        if (var->x == var->x_enemy && var->y == var->y_enemy)
        {
            mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		    free_all_and_exit_bonus(var);
        }
    }
    else if (var->str[var->y_enemy][var->x_enemy - 1] != '1' 
        && var->str[var->y_enemy][var->x_enemy - 1] != 'E'
        && var->str[var->y_enemy][var->x_enemy - 1] != 'C'
        && count_down == 0 && count_right == 0)
    {
        count_left++;
        count_down = 0;
        count_up = 0;
        count_right = 0;
        var->x_enemy -= 1;
        var->str[var->y_enemy][var->x_enemy] = 'M';
        var->str[var->y_enemy][var->x_enemy + 1] = '0';
        var->img_ptr_enemy = var->img_ptr_enemy = mlx_xpm_file_to_image(var->mlx_ptr, "textures/enemy_left.xpm", &width_img, &height_img);
        if (var->x == var->x_enemy && var->y == var->y_enemy)
        {
            mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		    free_all_and_exit_bonus(var);
        }
    }
    else if (var->str[var->y_enemy + 1][var->x_enemy] != '1' 
        && var->str[var->y_enemy + 1][var->x_enemy] != 'E'
        && var->str[var->y_enemy + 1][var->x_enemy] != 'C'
        && count_right == 0)
    {
        count_down++;
        count_up = 0;
        count_left = 0;
        count_right = 0;
        var->y_enemy += 1;
        var->str[var->y_enemy][var->x_enemy] = 'M';
        var->str[var->y_enemy - 1][var->x_enemy] = '0';
        var->img_ptr_enemy = var->img_ptr_enemy = mlx_xpm_file_to_image(var->mlx_ptr, "textures/enemy_down.xpm", &width_img, &height_img);
        if (var->x == var->x_enemy && var->y == var->y_enemy)
        {
            mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		    free_all_and_exit_bonus(var);
        }
    }
    else if (var->str[var->y_enemy][var->x_enemy + 1] != '1' 
        && var->str[var->y_enemy][var->x_enemy + 1] != 'E'
        && var->str[var->y_enemy][var->x_enemy + 1] != 'C')
    {
        count_right++;
        count_down = 0;
        count_left = 0;
        count_up = 0;
        var->x_enemy += 1;
        var->str[var->y_enemy][var->x_enemy] = 'M';
        var->str[var->y_enemy][var->x_enemy - 1] = '0';
        var->img_ptr_enemy = var->img_ptr_enemy = mlx_xpm_file_to_image(var->mlx_ptr, "textures/enemy_right.xpm", &width_img, &height_img);
        if (var->x == var->x_enemy && var->y == var->y_enemy)
        {
            mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		    free_all_and_exit_bonus(var);
        }
    }
    else
    count_right = 0;
        
}