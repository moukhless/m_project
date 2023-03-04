/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:11:30 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/04 00:33:27 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS
 #define SO_LONG_BONUS

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include "../get_next_line.h"

typedef struct s_var
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr_ground;
	void *img_ptr_wall;
	void *img_ptr_coll;
	void *img_ptr_exit;
    void *img_ptr_enemy;
	void *img_ptr_player;
	char **str;
	int x;
	int y;
	int x_enemy;
	int y_enemy;
	int width_win;
	int height_win;
	int number_of_coll;
	int number_of_player;
	int number_of_exit;
	int width_p;
	int height_p;
} t_var;

int handle_key_press_bonus(int keycode, t_var *var);
void map_bonus(t_var *var);
void map_next_bonus(t_var *var, int i, int j);
void print_M(t_var *var);
void print_C(t_var *var);
void print_E(t_var *var);
void print_P(t_var *var);
int is_a_wall_bonus(int x, int y, t_var *var);
int is_a_collectible_bonus(int x, int y, t_var *var);
int is_a_exit_bonus(int x, int y, t_var *var);
int is_a_enemy_bonus(int x, int y, t_var *var);
void key_up_bonus(t_var *var);
void key_down_bonus(t_var *var);
void key_right_bonus(t_var *var);
void key_left_bonus(t_var *var);
int move_up_bonus(t_var *var);
int move_down_bonus(t_var *var);
int move_right_bonus(t_var *var);
int move_left_bonus(t_var *var);
void free_all_and_exit_bonus(t_var *var);
int width_wind_bonus(char *string);
void height_width_wind_bonus(t_var *var, int fd);
void check_map_walls_bonus(t_var *var);
void check_map_bonus(t_var *var);
void check_map_is_playable_bonus(t_var *var);
void check_path_of_player_bonus(t_var *var , int check_x, int check_y, char **matrix);
void free_matrix_bonus(char **matrix);
void check_map_is_playable_next_bonus(t_var *var, char **matrix);
void mark_position_of_player_bonus(t_var *var, int *check_x, int *check_y, char **matrix);
void fill_map_in_matrix_bonus(t_var *var, int fd, char **argv);
void protect_img_bonus(t_var *var);
void fill_map_in_matrix_next_bonus(t_var *var, int fd);
int handle_key_press_bonus(int keycode, t_var *var);
int destroy_notify_handler(t_var *var);
int drawing_map(t_var *var);
void animation_of_coll(t_var *var ,int *count);
void animation_player_up(t_var *var, int *m_up);
void animation_player_down(t_var *var, int *m_down);
void animation_player_right(t_var *var, int *m_right);
void animation_player_left(t_var *var, int *m_left);
void enemy_movement(t_var *var);

#endif