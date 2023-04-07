/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:15:51 by amoukhle          #+#    #+#             */
/*   Updated: 2023/04/07 16:19:09 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_algo(t_stack *stack_a, t_stack *stack_b,
		int *arr, int count_num)
{
	sort_arr(arr, count_num);
	if (t_stack_size(stack_a) == 3 && check_stack_sorted(stack_a) == 0)
		sort_stack_size_3(&stack_a);
	else if (t_stack_size(stack_a) == 5 && check_stack_sorted(stack_a) == 0)
		sort_stack_size_5(stack_a, stack_b, arr, count_num);
	else
	{
		longest_increasing_subsequence(stack_a);
		move_to_stack_b(&stack_a, &stack_b);
		move_to_stack_a(&stack_a, &stack_b, arr, count_num - 1);
	}
	if (check_stack_sorted(stack_a) == 0)
		sort_stack(&stack_a, arr);
	free(arr);
	t_stack_clean(&stack_a);
	t_stack_clean(&stack_b);
}

int	main(int argc, char **argv)
{
	int		count_num;
	int		*arr;
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	count_num = check_is_number_and_integer(argc, argv);
	if (count_num == 0)
		return (1);
	arr = fill_arr(argc, argv, count_num);
	if (check_deplicate(arr, count_num) == 0)
		return (1);
	i = 0;
	stack_b = NULL;
	stack_a = NULL;
	while (i < count_num)
	{
		addnumber_back(&stack_a, new_number(arr[i], i, 1, count_num));
		i++;
	}
	do_algo(stack_a, stack_b, arr, count_num);
	return (0);
}
