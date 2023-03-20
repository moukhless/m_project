/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:17:37 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/20 20:37:58 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_next1(t_stack *stack_a, t_stack *stack_b, char *inp)
{
	int		i;
	char	**sort;

	i = 0;
	if (!inp)
	{
		result(stack_a, stack_b);
		exit (0);
	}
	sort = ft_split(inp, '\n');
	free(inp);
	while (sort[i])
		do_instructions(sort, &stack_a, &stack_b, i++);
	free_double_str(sort);
	result(stack_a, stack_b);
}

void	free_double_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
}

void	result(t_stack *stack_a, t_stack *stack_b)
{
	if (t_stack_size(stack_a) != 0)
	{
		if (check_stack_sorted(stack_a) == 1 && t_stack_size(stack_b) == 0)
			write(1, "OK\n", 3);
		else
			write(2, "KO\n", 3);
	}
	else
		write(2, "KO\n", 3);
	t_stack_clean(&stack_a);
	t_stack_clean(&stack_b);
}

int	main(int argc, char **argv)
{
	int		count_num;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		*arr;

	count_num = check_is_number_and_integer(argc, argv);
	if (count_num == 0)
		return (-1);
	arr = fill_arr(argc, argv, count_num);
	if (check_deplicate(arr, count_num) == 0)
		return (-1);
	i = 0;
	stack_b = NULL;
	stack_a = NULL;
	while (i < count_num)
	{
		addnumber_back(&stack_a, new_number(arr[i], i, 1, count_num));
		i++;
	}
	free(arr);
	checker_next(stack_a, stack_b);
	exit (0);
}
