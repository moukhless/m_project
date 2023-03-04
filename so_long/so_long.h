/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 03:26:27 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/02 23:42:38 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
 #define SO_LONG

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"


typedef struct s_var
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr_ground;
	void *img_ptr_wall;
	void *img_ptr_coll;
	void *img_ptr_coll1;
	void *img_ptr_coll2;
	void *img_ptr_coll3;
	void *img_ptr_coll4;
	void *img_ptr_coll5;
	void *img_ptr_coll6;
	void *img_ptr_coll7;
	void *img_ptr_coll8;
	void *img_ptr_exit;
	void *img_ptr_player;
	char **str;
	int width;
	int height;
	int width_win;
	int height_win;
	int number_of_coll;
	int number_of_player;
	int number_of_exit;
	int width_p;
	int height_p;
} t_var;

int is_a_wall(int width, int height, t_var *var);
int is_a_collectible(int width, int height, t_var *var);
int is_a_exit(int width, int height, t_var *var);
void map(t_var *var);
int move_up(t_var *var);
int move_down(t_var *var);
int move_right(t_var *var);
int move_left(t_var *var);
int handle_key_press(int keycode, t_var *var);
void key_up(t_var *var);
void key_down(t_var *var);
void key_right(t_var *var);
void key_left(t_var *var);
int width_wind(char *string);
void height_width_wind(t_var *var, int fd);
void check_map(t_var *var);
void check_map_walls(t_var *var);
void free_all_and_exit(t_var *var);
void check_map_walls(t_var *var);
void map_next(t_var *var, int i, int j);
int destroy_notify_handler(t_var *var);
void fill_map_in_matrix(t_var *var, int fd, char **argv);
void fill_map_in_matrix_next(t_var *var, int fd);
int handle_key_press(int keycode, t_var *var);
void print_C(t_var *var);
void print_E(t_var *var);
void print_P(t_var *var);
void protect_img(t_var *var);
void check_map_is_playable(t_var *var);
void check_path_of_player(t_var *var , int check_x, int check_y, char **matrix);
void check_map_is_playable_next(t_var *var, char **matrix);
void mark_position_of_player(t_var *var, int *check_x, int *check_y, char **matrix);
void free_matrix(char **matrix);
/**********************************/
void map_next_bonus(t_var *var, int i, int j);
void map_bonus(t_var *var);
int animation_of_coll(t_var *var);



#endif