/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_for_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:47:53 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/28 00:04:39 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_listchr(t_list *list, int type)
{
	while (list && list->type_d != PIPE_LINE)
	{
		if (list->type_d == type)
			return (0);
		list = list->next;
	}
	return (1);
}

int	ft_serche_in_list(t_list *last_list, char *cmd)
{
	while (last_list && (last_list)->type_d != PIPE_LINE)
	{
		if ((last_list)->type_d == WORD)
		{
			if (ft_strcmp(cmd, last_list->cmd[0]) == 0)
				return (0);
		}
		last_list = (last_list)->next;
	}
	return (1);
}

void	ft_serche_for_heredoce(t_list *last_list,
				t_var *var, t_list_str **list_heredoce)
{
	int	file;
	int	other_hd;

	other_hd = 0;
	while (last_list)
	{
		if (last_list->type_d == HERE_DOC)
		{
			file = ft_open_heredoc(last_list, var);
			list_stradd_back(list_heredoce, new_list_str(NULL, file));
		}
		last_list = last_list->next;
	}
}
