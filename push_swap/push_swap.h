/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:13:30 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/20 19:54:47 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct l_t_stack
{
	int					number;
	int					index;
	int					status;
	int					next_index;
	struct l_t_stack	*next;
}	t_stack;

t_stack	*new_number(int number, int index, int status, int next_index);
void	addnumber_front(t_stack **s_list, t_stack *s_new);
void	addnumber_back(t_stack **s_list, t_stack *s_new);
int		t_stack_size(t_stack *s_list);
void	t_stack_clean(t_stack **s_list);
void	swap(t_stack **s_list);
void	push(t_stack **s_list_a, t_stack **s_list_b);
void	rotate(t_stack **s_list);
void	reverse_rotate(t_stack **s_list);
long	ft_atoi(char *str);
int		check_is_number(char *number);
int		check_deplicate(int *arr, int count_num);
int		check_is_integer(char *number);
int		check_is_number_and_integer(int argc, char **argv);
char	**ft_split(char *s, char c);
char	*fill_str(char **st, char *s, int start, int end);
int		num_w(char *str, char c);
int		*fill_arr(int argc, char **argv, int count_num);
void	sort_arr(int *arr, int count_num);
int		check_stack_sorted(t_stack *s_list);
void	longest_increasing_subsequence(t_stack *stack_a);
void	move_to_stack_b(t_stack **stack_a, t_stack **stack_b);
int		longest_list(t_stack *stack_a);
void	reset_index(t_stack *stack_a);
void	move_to_stack_b_next(t_stack *p, t_stack **stack_a, t_stack **stack_b);
int		*arr_longest_list(t_stack *p);
int		find_number_in_arr(int number, int *arr, int edge_of_arr);
void	move_to_stack_b_next1(t_stack *p, t_stack **stack_a,
			t_stack **stack_b);
void	reset_status(t_stack *stack_b);
void	move_to_stack_a(t_stack **stack_a, t_stack **stack_b,
			int *arr, int edge_of_arr);
int		find_next_number_in_arr(t_stack *stack_a, int number,
			int *arr, int edge_of_arr);
int		find_number_in_stack(int number, t_stack *stack_a);
void	reset_movement(t_stack *stack_a, t_stack *stack_b,
			int *arr, int egde_of_arr);
int		min_movement(t_stack *stack_b);
void	same_move(t_stack **stack_a, t_stack **stack_b,
			t_stack *p, t_stack *p1);
void	move_to_stack_a_next(t_stack **stack_a, t_stack **stack_b,
			int *arr, int edge_of_arr);
void	sort_stack(t_stack **stack_a, int *arr);
void	calcul_mov1(t_stack *s_b, t_stack *s_a, t_stack *stack_b);
void	calcul_mov2(t_stack *s_b, t_stack *s_a,
			t_stack *stack_a, t_stack *stack_b);
void	calcul_mov3(t_stack *s_b, t_stack *s_a);
void	calcul_mov4(t_stack *s_b, t_stack *s_a,
			t_stack *stack_a, t_stack *stack_b);
void	do_same_move1(t_stack **stack_a, t_stack **stack_b,
			t_stack *s_b, t_stack *s_a);
void	do_same_move2(t_stack **stack_a, t_stack **stack_b,
			t_stack *s_b, t_stack *s_a);
void	move_to_stack_a_next1(t_stack **stack_a, t_stack **stack_b,
			t_stack *s_a, t_stack *s_b);
void	do_rotate_a(t_stack **stack_a, t_stack *s_a);
void	do_rotate_b(t_stack **stack_b, t_stack *s_b);
void	do_reverse_rotate_a(t_stack **stack_a, t_stack *s_a);
void	do_reverse_rotate_b(t_stack **stack_b, t_stack *s_b);
void	do_algo(t_stack *stack_a, t_stack *stack_b, int *arr, int count_num);
void	sort_stack_size_3(t_stack **stack_a, t_stack **stack_b);
void	sort_stack_size_3_next(t_stack **stack_a,
			t_stack **stack_b, t_stack *s_a);
void	sort_stack_size_5(t_stack *stack_a, t_stack *stack_b,
			int *arr, int edge_of_arr);
void	sort_stack_size_5_next(t_stack *stack_a, t_stack *stack_b,
			int *arr, int edge_of_arr);
int		ft_strcmp(char *str1, char *str2);
void	check_input(char *str);
void	do_instructions(char **sort, t_stack **stack_a,
			t_stack **stack_b, int i);
void	checker_next(t_stack *stack_a, t_stack *stack_b);
void	do_instructions_next(char **sort, t_stack **stack_a,
			t_stack **stack_b, int i);
void	result(t_stack *stack_a, t_stack *stack_b);
void	free_double_str(char **str);
void	checker_next1(t_stack *stack_a, t_stack *stack_b, char *inp);
void	reset_movement_next(t_stack *stack_a, t_stack *stack_b,
			t_stack *s_a, t_stack *s_b);
void	sort_stack_next(t_stack **stack_a, t_stack *p);

#endif
