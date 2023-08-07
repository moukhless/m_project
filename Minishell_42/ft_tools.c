/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:01:49 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/28 00:02:43 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	serche_for_doc(t_list *list)
{
	if (list->type == WORD || list->type == Q_MARK)
		list = list->prev;
	if (list->type == ENV)
		list = list->prev;
	while (list && (list->type == WORD || list->type == QOUTE
			|| list->type == DOUBLE_QUOTE || list->type == Q_MARK
			|| list->state == IN_DQUOTE || list->state == IN_QUOTE
			|| list->type == ENV || list->type == SPECIAL_CHAR))
		list = list->prev;
	while (list && list->type == WHITE_SPACE && list->state == GENERAL)
		list = list->prev;
	if (list && (list->type == HERE_DOC || list->type == DREDIR_OUT
			|| list->type == REDIR_IN || list->type == REDIR_OUT)
		&& list->state == GENERAL)
		return (0);
	return (1);
}

void	free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	is_doc(t_list *list)
{
	if ((list->type == REDIR_IN || list->type == REDIR_OUT
			|| list->type == HERE_DOC || list->type == DREDIR_OUT)
		&& list->state == GENERAL)
		return (0);
	return (1);
}

int	is_word(t_list *head)
{
	if (head->type != WORD && head->type != QOUTE && head->type != Q_MARK
		&& head->type != DOUBLE_QUOTE && head->type != ENV
		&& head->type != SPECIAL_CHAR)
		return (1);
	return (0);
}

int	get_value(int value)
{
	static int	v;

	if (value != -1)
		v = value;
	return (v);
}
