/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_quotes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 06:28:18 by hachahbo          #+#    #+#             */
/*   Updated: 2023/07/27 23:44:55 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_d_quote(t_list *head)
{
	int		x;
	int		i;
	t_list	*help;

	x = 0;
	help = head;
	while (head)
	{
		if (ft_strcmp(head->content, "\"") == 0 && head->state == GENERAL)
			x++;
		head = head ->next;
	}
	i = 0;
	while (help)
	{
		if (ft_strcmp(help->content, "\'") == 0 && help->state == GENERAL)
			i++;
		help = help ->next;
	}
	if ((x % 2 != 0) || (i % 2 != 0))
	{
		printf("syntax error\n");
		return (1);
	}
	return (0);
}
