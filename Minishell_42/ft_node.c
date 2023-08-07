/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:05:18 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/27 23:53:57 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_node(t_list **new_list, char *str, int in_join)
{
	t_list	*new;

	new = ft_lstnew(str, NULL);
	if (in_join == 0)
		new->state = GENERAL;
	else
		new->state = IN_DQUOTE;
	ft_lstadd_back(new_list, new);
}

int	join_node(t_list *head)
{
	if (head->type == WORD || head->type == ENV || head->type == Q_MARK
		|| head->type == QOUTE || head->type == DOUBLE_QUOTE
		|| head->type == SPECIAL_CHAR
		|| head->state == IN_QUOTE || head->state == IN_DQUOTE)
		return (0);
	return (1);
}

int	skip_node(t_list *head, int num_env)
{
	if ((head->type == QOUTE && head->state == GENERAL
			&& serche_for_doc(head) == 1)
		|| (head->type == DOUBLE_QUOTE && head->state == GENERAL
			&& serche_for_doc(head) == 1)
		|| ((head->type == WORD || head->type == Q_MARK)
			&& head->prev && head->prev->type == ENV
			&& head->state != IN_QUOTE && num_env % 2 != 0
			&& serche_for_doc(head) == 1))
		return (0);
	return (1);
}

void	ft_skip_node(t_var *var, t_list *head)
{
	if (!var->str && (head->type == DOUBLE_QUOTE || head->type == QOUTE))
		var->str = "";
	var->num_env = 0;
	var->skip = 1;
}
