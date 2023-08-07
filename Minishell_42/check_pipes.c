/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 06:31:48 by hachahbo          #+#    #+#             */
/*   Updated: 2023/07/27 23:41:42 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_pipes(t_list *head)
{
	int	x;

	x = 0;
	while (head)
	{
		if (head->type != PIPE_LINE && !is_spaces(head->content))
			x = 1;
		if (head->type == PIPE_LINE)
		{
			head = head->next;
			while (head && is_spaces(head->content))
				head = head->next;
			if (!head || head->type == PIPE_LINE || x == 0)
			{
				printf("bash: syntax error near unexpected token `|'\n");
				return (1);
			}
		}
		head = head->next;
	}
	return (0);
}
