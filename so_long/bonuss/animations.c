/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:25:53 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/04 00:08:27 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void animation_of_coll(t_var *var ,int *count)
{
	int width_img;
	int height_img;
	
	if (*count == 7)
		var->img_ptr_coll = var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr, "textures/collectible1.xpm", &width_img, &height_img);
	if (*count == 14)
		var->img_ptr_coll = var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr, "textures/collectible2.xpm", &width_img, &height_img);
	if (*count == 21)
		var->img_ptr_coll = var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr, "textures/collectible3.xpm", &width_img, &height_img);
	if (*count == 28)
		var->img_ptr_coll = var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr, "textures/collectible4.xpm", &width_img, &height_img);
	if (*count == 35)
		var->img_ptr_coll = var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr, "textures/collectible5.xpm", &width_img, &height_img);
	if (*count == 42)
		var->img_ptr_coll = var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr, "textures/collectible6.xpm", &width_img, &height_img);
	if (*count == 49)
		var->img_ptr_coll = var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr, "textures/collectible7.xpm", &width_img, &height_img);
	if (*count == 56)
		var->img_ptr_coll = var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr, "textures/collectible8.xpm", &width_img, &height_img);
	if (*count == 63)
	{
		var->img_ptr_coll = var->img_ptr_coll = mlx_xpm_file_to_image(var->mlx_ptr, "textures/collectible4.xpm", &width_img, &height_img);
		*count = 0;
	}
}

void animation_player_up(t_var *var, int *m_up)
{
	int width_img;
	int height_img;
	
	(*m_up)++;
	if (*m_up == 1)
		var->img_ptr_player = var->img_ptr_player = mlx_xpm_file_to_image(var->mlx_ptr, "textures/player_up.xpm", &width_img, &height_img);
	if (*m_up == 2)
	{
		var->img_ptr_player = var->img_ptr_player = mlx_xpm_file_to_image(var->mlx_ptr, "textures/player_up1.xpm", &width_img, &height_img);
		*m_up = 0;
	}
	key_up_bonus(var);
}

void animation_player_down(t_var *var, int *m_down)
{
	int width_img;
	int height_img;
	
	(*m_down)++;
	if (*m_down == 1)
		var->img_ptr_player = var->img_ptr_player = mlx_xpm_file_to_image(var->mlx_ptr, "textures/player_down.xpm", &width_img, &height_img);
	if (*m_down == 2)
	{
		var->img_ptr_player = var->img_ptr_player = mlx_xpm_file_to_image(var->mlx_ptr, "textures/player_down1.xpm", &width_img, &height_img);
		*m_down = 0;
	}
	key_down_bonus(var);
}

void animation_player_right(t_var *var, int *m_right)
{
	int width_img;
	int height_img;
	
	(*m_right)++;
	if (*m_right == 1)
		var->img_ptr_player = var->img_ptr_player = mlx_xpm_file_to_image(var->mlx_ptr, "textures/player_right1.xpm", &width_img, &height_img);
	if (*m_right == 2)
	{
		var->img_ptr_player = var->img_ptr_player = mlx_xpm_file_to_image(var->mlx_ptr, "textures/player_right4.xpm", &width_img, &height_img);
		*m_right = 0;
	}
	key_right_bonus(var);
}

void animation_player_left(t_var *var, int *m_left)
{
	int width_img;
	int height_img;
	
	(*m_left)++;
	if (*m_left == 1)
		var->img_ptr_player = var->img_ptr_player = mlx_xpm_file_to_image(var->mlx_ptr, "textures/player_left1.xpm", &width_img, &height_img);
	if (*m_left == 2)
	{
		var->img_ptr_player = var->img_ptr_player = mlx_xpm_file_to_image(var->mlx_ptr, "textures/player_left4.xpm", &width_img, &height_img);
		*m_left = 0;
	}
	key_left_bonus(var);
}