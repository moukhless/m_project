/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_option_DOC.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:39:45 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/28 00:19:05 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handle_env_doc(t_list *list, t_env *env_list, int num_env)
{
	if ((list->type == ENV && list->state == GENERAL
			&& (list->next == NULL || list->next->type == WHITE_SPACE))
		|| (list->type == ENV && list->state == IN_QUOTE))
		return (list->content);
	else if (list->type == ENV && list->state == GENERAL && num_env % 2 != 0
		&& (list->next->type == QOUTE || list->next->type == DOUBLE_QUOTE))
		return ("");
	else if (list->type == ENV && (list->state == IN_DQUOTE
			|| list->state == GENERAL))
	{
		if (list->next->type == WORD && num_env % 2 != 0)
			return (ft_expand_value(list->next->content, env_list));
		else if (list->next->type == Q_MARK && num_env % 2 != 0)
			return (ft_itoa(g_state_exit));
	}
	return (list->content);
}

void	ft_init_var(t_var *var)
{
	var->start = 0;
	var->end = 0;
	var->flag1 = 0;
	var->flag2 = 0;
	var->num_env = 0;
	var->q_dq = 0;
	var->str = NULL;
}

int	skip_node_doc(t_list *list, t_var *var)
{
	if ((list->type == QOUTE && list->state == GENERAL)
		|| (list->type == DOUBLE_QUOTE && list->state == GENERAL)
		|| ((list->type == WORD || list->type == Q_MARK)
			&& list->prev && list->prev->type == ENV
			&& list->state != IN_QUOTE && var->num_env % 2 != 0))
		return (0);
	return (1);
}

void	ft_skip_node_doc(t_list *list, t_var *var)
{
	if (!var->str && (list->type == DOUBLE_QUOTE || list->type == QOUTE))
		var->str = "";
	var->num_env = 0;
	var->skip = 1;
}

char	*get_string_doc(t_list *list, t_var *var,
				t_env *env_list, t_list_str **list_str)
{
	char	*tmp;

	while (list)
	{
		var->skip = 0;
		if (!skip_node_doc(list, var))
			ft_skip_node_doc(list, var);
		if (!var->skip && list->type == ENV)
		{
			var->num_env++;
			tmp = handle_env_doc(list, env_list, var->num_env);
			if (!tmp || (list->state == GENERAL
					&& ft_strcmp(tmp, "$") && ft_strchr(tmp, ' ')))
				var->skip = 1;
			if (!var->skip)
				var->str = join_list_str(var->str, tmp, list_str);
		}
		else if (!var->skip)
			var->str = join_list_str(var->str, list->content, list_str);
		list = list->next;
	}
	return (var->str);
}
