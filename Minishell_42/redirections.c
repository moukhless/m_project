/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 06:34:56 by hachahbo          #+#    #+#             */
/*   Updated: 2023/07/28 00:15:49 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redirection(char *str)
{
	if (!ft_strcmp(str, "<<"))
		return (1);
	if (!ft_strcmp(str, "<"))
		return (1);
	if (!ft_strcmp(str, ">>"))
		return (1);
	if (!ft_strcmp(str, ">"))
		return (1);
	return (0);
}

int	check_num_herdoc(t_list *head)
{
	int	num;

	num = 0;
	while (head)
	{
		if (head->type == HERE_DOC)
			num++;
		head = head->next;
	}
	if (num > 16)
	{
		printf("bash: maximum here-document count exceeded\n");
		return (1);
	}
	return (0);
}

void	print_sysntax_error(t_list *head)
{
	if (!head)
	{
		printf("bash: syntax error near unexpected ");
		printf("token `newline'\n");
	}
	else if (head->type == PIPE_LINE)
		printf("bash: syntax error near unexpected token `|'\n");
	else if (is_redirection(head->content))
	{
		printf("bash: syntax error near unexpected token ");
		printf("`%s'\n", head->content);
	}
}

int	check_redirection(t_list *head)
{
	while (head)
	{
		if (is_redirection(head->content))
		{
			head = head->next;
			while (head && is_spaces(head->content))
				head = head->next;
			if (!head || head->type == PIPE_LINE
				|| is_redirection(head->content))
			{
				print_sysntax_error(head);
				return (1);
			}
		}
		head = head ->next;
	}
	return (0);
}
