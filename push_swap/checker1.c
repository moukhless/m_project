/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:32:01 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/20 20:39:16 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	check_input(char *str)
{
	if (str != NULL)
	{
		if (ft_strcmp(str, "sa\n") != 0 && ft_strcmp(str, "sb\n") != 0
			&& ft_strcmp(str, "pa\n") != 0 && ft_strcmp(str, "pb\n") != 0
			&& ft_strcmp(str, "ra\n") != 0 && ft_strcmp(str, "rb\n") != 0
			&& ft_strcmp(str, "rra\n") != 0 && ft_strcmp(str, "rrb\n") != 0
			&& ft_strcmp(str, "rr\n") != 0 && ft_strcmp(str, "rrr\n") != 0
			&& ft_strcmp(str, "ss\n") != 0)
		{
			write(2, "Error\n", 6);
			exit (0);
		}
	}
}

void	do_instructions(char **sort, t_stack **stack_a,
		t_stack **stack_b, int i)
{
	if (ft_strcmp(sort[i], "sa") == 0 && t_stack_size(*stack_a) != 0
		&& t_stack_size(*stack_a) != 1)
		swap(stack_a);
	else if (ft_strcmp(sort[i], "sb") == 0 && t_stack_size(*stack_b) != 0
		&& t_stack_size(*stack_b) != 1)
		swap(stack_b);
	else if (ft_strcmp(sort[i], "ss") == 0)
	{
		if (t_stack_size(*stack_a) != 0 && t_stack_size(*stack_a) != 1)
			swap(stack_a);
		if (t_stack_size(*stack_b) != 0 && t_stack_size(*stack_b) != 1)
			swap(stack_b);
	}
	else if (ft_strcmp(sort[i], "pa") == 0 && t_stack_size(*stack_b) != 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(sort[i], "pb") == 0 && t_stack_size(*stack_a) != 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(sort[i], "ra") == 0 && t_stack_size(*stack_a) != 0)
		rotate(stack_a);
	else if (ft_strcmp(sort[i], "rb") == 0 && t_stack_size(*stack_b) != 0)
		rotate(stack_b);
	else
		do_instructions_next(sort, stack_a, stack_b, i);
}

void	do_instructions_next(char **sort, t_stack **stack_a,
		t_stack **stack_b, int i)
{
	if (ft_strcmp(sort[i], "rr") == 0)
	{
		if (t_stack_size(*stack_a) != 0)
			rotate(stack_a);
		if (t_stack_size(*stack_b) != 0)
			rotate(stack_b);
	}
	else if (ft_strcmp(sort[i], "rra") == 0 && t_stack_size(*stack_a) != 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(sort[i], "rrb") == 0 && t_stack_size(*stack_b) != 0)
		reverse_rotate(stack_b);
	else if (ft_strcmp(sort[i], "rrr") == 0)
	{
		if (t_stack_size(*stack_a) != 0)
			reverse_rotate(stack_a);
		if (t_stack_size(*stack_b) != 0)
			reverse_rotate(stack_b);
	}
}

void	checker_next(t_stack *stack_a, t_stack *stack_b)
{
	char	*inp;
	char	*str;

	inp = NULL;
	while (1)
	{
		str = get_next_line(0);
		check_input(str);
		if (str)
		{
			inp = ft_strjoin(inp, str);
			free(str);
		}
		else
		{
			checker_next1(stack_a, stack_b, inp);
			break ;
		}
	}
}
