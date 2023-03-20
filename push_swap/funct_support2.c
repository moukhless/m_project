/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_support2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:40:03 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/20 19:11:38 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_status(t_stack *stack_b)
{
	while (stack_b)
	{
		stack_b->status = 0;
		stack_b = stack_b->next;
	}
}

int	find_next_number_in_arr(t_stack *stack_a, int number,
		int *arr, int edge_of_arr)
{
	int	i;

	i = 0;
	while (i <= edge_of_arr)
	{
		if (number == arr[i])
			break ;
		i++;
	}
	if (i == edge_of_arr)
		i = 0;
	else
		i++;
	while (find_number_in_stack(arr[i], stack_a) == 0)
	{
		if (i == edge_of_arr)
			i = 0;
		else
			i++;
	}
	return (arr[i]);
}

int	find_number_in_stack(int number, t_stack *stack_a)
{
	while (stack_a)
	{
		if (number == stack_a->number)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	sort_stack(t_stack **stack_a, int *arr)
{
	t_stack	*p;

	p = *stack_a;
	while (p)
	{
		if (p->number == arr[0])
			break ;
		p = p->next;
	}
	if (p->index <= (t_stack_size(*stack_a) / 2))
	{
		while (p->index > 0)
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
			(p->index)--;
		}
	}
	else
		sort_stack_next(stack_a, p);
}

void	sort_stack_next(t_stack **stack_a, t_stack *p)
{
	if (p->index > (t_stack_size(*stack_a) / 2))
	{
		while (p->index < t_stack_size(*stack_a))
		{
			reverse_rotate(stack_a);
			write(1, "rra\n", 4);
			(p->index)++;
		}
	}
}
