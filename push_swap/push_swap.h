/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:13:30 by amoukhle          #+#    #+#             */
/*   Updated: 2023/02/10 02:22:44 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct l_t_stack
{
    int number;
    int index;
    int status;
    int next_index;
    struct l_t_stack *next;
} t_stack;

t_stack *new_number(int number, int index, int status, int next_index);
void addnumber_front(t_stack **s_list, t_stack *s_new);
void addnumber_back(t_stack **s_list, t_stack *s_new);
int t_stack_size(t_stack *s_list);
void t_stack_clean(t_stack **s_list);
void swap(t_stack **s_list);
void push(t_stack **s_list_a, t_stack **s_list_b);
void rotate(t_stack **s_list);
void reverse_rotate(t_stack **s_list);
long ft_atoi(char *str);
int check_is_number(char *number);
int check_deplicate(int *arr);
int check_is_integer(char *number);
int check_is_number_and_integer(int argc, char **argv);
char	**ft_split(char *s, char c);
char	*fill_str(char **st, char *s, int start, int end);
int	num_w(char *str, char c);
int *fill_arr(int argc, char **argv, int count_num);
void sort_arr(int *arr, int count_num);
int check_stack_sorted(t_stack *s_list);
void longest_increasing_subsequence(t_stack *stack_a);
void move_to_stack_b(t_stack **stack_a , t_stack **stack_b);
int longest_list(t_stack *stack_a);
void reset_index(t_stack *stack_a);
void move_to_stack_b_next(t_stack *p ,t_stack **stack_a, t_stack **stack_b);
int *arr_longest_list(t_stack *p);
int find_number_in_arr(int number, int *arr, int edge_of_arr);
void move_to_stack_b_next1(t_stack *p ,t_stack **stack_a, t_stack **stack_b);
void reset_status(t_stack *stack_b);
void move_to_stack_a(t_stack **stack_a, t_stack **stack_b, int *arr, int edge_of_arr);
int find_next_number_in_arr(t_stack *stack_a ,int number, int *arr, int edge_of_arr);
int find_number_in_stack(int number, t_stack *stack_a);
void reset_movement(t_stack *stack_a, t_stack *stack_b, int *arr, int egde_of_arr);
int min_movement(t_stack *stack_b);
void same_move(t_stack **stack_a, t_stack **stack_b, t_stack *p, t_stack *p1);
void move_to_stack_a_next(t_stack **stack_a, t_stack **stack_b, int *arr, int edge_of_arr);
void sort_stack(t_stack **stack_a, int *arr);
void affiche_stack(t_stack *stack);

#endif