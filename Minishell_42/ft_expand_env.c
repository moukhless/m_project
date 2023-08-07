/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:03:57 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/29 18:22:10 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*generate_value_of_env(char *str, char *tmp,
				t_list_str **list_str, t_list **new_list)
{
	int		i;
	char	**str_split;

	str_split = ft_spaces_split(tmp);
	free(tmp);
	i = 0;
	while (str_split[i] && str_split[i + 1])
	{
		str = ft_strjoin(str, str_split[i]);
		list_stradd_back(list_str, new_list_str(str, 0));
		i++;
		ft_lstadd_back(new_list, ft_lstnew(str, NULL));
		str = NULL;
	}
	str = ft_strjoin(str, str_split[i]);
	list_stradd_back(list_str, new_list_str(str, 0));
	free_double(str_split);
	return (str);
}

char	*handle_env(t_list *list, t_env *env_list, int num_env)
{
	char	*str;

	if ((list->type == ENV && list->state == GENERAL
			&& (list->next == NULL || list->next->type == WHITE_SPACE))
		|| (list->type == ENV && list->state == IN_QUOTE))
		return (ft_strdup(list->content));
	else if (list->type == ENV && list->state == GENERAL && num_env % 2 != 0
		&& (list->next->type == QOUTE || list->next->type == DOUBLE_QUOTE))
		return (ft_strdup(""));
	else if (list->type == ENV && (list->state == IN_DQUOTE
			|| list->state == GENERAL))
	{
		if (list->next->type == WORD && num_env % 2 != 0
			&& serche_for_doc(list) == 1)
		{
			str = ft_expand_value(list->next->content, env_list);
			if (str)
				return (ft_strdup(str));
			return (str);
		}
		else if (list->next->type == Q_MARK && num_env % 2 != 0
			&& serche_for_doc(list) == 1)
			return (ft_itoa(g_state_exit));
	}
	return (ft_strdup(list->content));
}

char	*ft_expand_value(char *str, t_env *env_list)
{
	char	*value;
	t_env	*tmp;

	value = NULL;
	tmp = env_list;
	while (env_list)
	{
		if (ft_strncmp(str, env_list->content, ft_strlen(str)) == 0
			&& env_list->content[ft_strlen(str)] == '=')
			value = &env_list->content[ft_strlen(str) + 1];
		env_list = env_list->next;
	}
	if (!value && ft_strcmp("PATH", str) == 0)
		value = tmp->hide_path;
	return (value);
}
