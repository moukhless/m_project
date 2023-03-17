/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:11:30 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/08 22:55:07 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include "../get_next_line.h"

typedef struct s_enemy
{
	int				x_enemy;
	int				y_enemy;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_var
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr_ground;
	void	*img_ptr_wall;
	void	*img_ptr_coll;
	void	*img_ptr_exit;
	void	*img_ptr_player;
	void	*img_ptr_enemy;
	char	**str;
	int		x;
	int		y;
	int		width_win;
	int		height_win;
	int		number_of_coll;
	int		number_of_player;
	int		number_of_exit;
	int		width_p;
	int		height_p;
	t_enemy	*enemy;
	int		*score;
	int		color;
	char	*s;
}	t_var;

int		handle_key_press_bonus(int keycode, t_var *var);
void	map_bonus(t_var *var);
void	map_next_bonus(t_var *var, int i, int j);
void	print_m(t_var *var);
void	print_c(t_var *var);
void	print_e(t_var *var);
void	print_p(t_var *var);
int		is_a_wall_bonus(int x, int y, t_var *var);
int		is_a_collectible_bonus(int x, int y, t_var *var);
int		is_a_exit_bonus(int x, int y, t_var *var);
int		is_a_enemy_bonus(int x, int y, t_var *var);
void	key_up_bonus(t_var *var);
void	key_down_bonus(t_var *var);
void	key_right_bonus(t_var *var);
void	key_left_bonus(t_var *var);
int		move_up_bonus(t_var *var);
int		move_down_bonus(t_var *var);
int		move_right_bonus(t_var *var);
int		move_left_bonus(t_var *var);
void	free_all_and_exit_bonus(t_var *var);
int		width_wind_bonus(char *string);
void	height_width_wind_bonus(t_var *var, int fd);
void	check_map_walls_bonus(t_var *var);
void	check_map_bonus(t_var *var);
void	check_map_is_playable_bonus(t_var *var);
void	check_path_of_player_bonus(t_var *var, int check_x,
			int check_y, char **matrix);
void	free_matrix_bonus(char **matrix);
void	check_map_is_playable_next_bonus(t_var *var, char **matrix);
void	mark_position_of_player_bonus(t_var *var, int *check_x,
			int *check_y, char **matrix);
void	fill_map_in_matrix_bonus(t_var *var, int fd, char **argv);
void	protect_img_bonus(t_var *var);
void	fill_map_in_matrix_next_bonus(t_var *var, int fd);
int		handle_key_press_bonus(int keycode, t_var *var);
int		destroy_notify_handler(t_var *var);
int		drawing_map(t_var *var);
void	animation_of_coll(t_var *var, int *count);
void	animation_player_up(t_var *var, int *m_up);
void	animation_player_down(t_var *var, int *m_down);
void	animation_player_right(t_var *var, int *m_right);
void	animation_player_left(t_var *var, int *m_left);
void	enemy_movement(t_enemy *enemy, t_var *var);
void	animation_of_exit(t_var *var, int *count_exit);
void	enemy_move_up(t_enemy *enemy, t_var *var);
void	enemy_move_down(t_enemy *enemy, t_var *var);
void	enemy_move_right(t_enemy *enemy, t_var *var);
void	enemy_move_left(t_enemy *enemy, t_var *var);
int		check_all_caracters(int x, int y, t_var *var);
void	animation_of_coll_and_exit(t_var *var, int *count_coll,
			int *count_exit);
void	animation_of_enemy(t_var *var, int *count_e);
void	animation_of_coll_next(t_var *var, int *count);
t_enemy	*new_enemy(int x_enemy, int y_enemy);
void	addenemy(t_enemy **s_enemy, t_enemy *n_enemy);
void	t_enemy_clean(t_enemy **s_enemy);
void	follow_player_up(t_enemy *enemy, t_var *var);
void	follow_player_down(t_enemy *enemy, t_var *var);
void	follow_player_right(t_enemy *enemy, t_var *var);
void	follow_player_left(t_enemy *enemy, t_var *var);
void	fill_matrix_bonus(t_var *var, char **matrix);
int		count_num(int num);
char	*itoa(int num);
char	*scores(t_var *var, int num);
void	map_next_bonus1(t_var *var, int i, int j);
void	initialisation_bonus(t_var *var);

#endif
