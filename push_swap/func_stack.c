/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_t_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:21:43 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/20 16:53:04 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_number(int number, int index, int status, int next_index)
{
	t_stack	*s_new;

	s_new = (t_stack *)malloc(sizeof(t_stack));
	if (!s_new)
		return (NULL);
	s_new->number = number;
	s_new->index = index;
	s_new->status = status;
	s_new->next_index = next_index;
	s_new->next = NULL;
	return (s_new);
}

void	addnumber_front(t_stack **s_list, t_stack *s_new)
{
	t_stack	*p;

	if (!*s_list)
	{
		*s_list = s_new;
		return ;
	}
	p = *s_list;
	*s_list = s_new;
	s_new->next = p;
}

void	addnumber_back(t_stack **s_list, t_stack *s_new)
{
	t_stack	*p;

	if (!*s_list)
	{
		*s_list = s_new;
		return ;
	}
	p = *s_list;
	while (p->next)
		p = p->next;
	p->next = s_new;
}

int	t_stack_size(t_stack *s_list)
{
	int	count;

	count = 0;
	while (s_list)
	{
		s_list = s_list->next;
		count++;
	}
	return (count);
}

void	t_stack_clean(t_stack **s_list)
{
	t_stack	*p;

	p = *s_list;
	while (*s_list)
	{
		p = (*s_list)->next;
		free(*s_list);
		*s_list = p;
	}
}
