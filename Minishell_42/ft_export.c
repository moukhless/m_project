/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:15:35 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/30 11:49:20 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_is_valid(t_env *new_env, t_var *var)
{
	int		i;
	char	*str;

	str = NULL;
	if (!(ft_isalpha(new_env->key[0]) || new_env->key[0] == '_'))
		return (ft_print_error(new_env->key, new_env, str, var), 0);
	i = 1;
	while (new_env->key[i])
	{
		if (!ft_isalpha(new_env->key[i])
			&& !ft_isdigit(new_env->key[i]) && !(new_env->key[i] == '_'))
			return (ft_print_error(new_env->key, new_env, str, var), 0);
		i++;
	}
	i = ft_strlen(new_env->content);
	if (new_env->content[i - 1] == '+' && !new_env->content[i])
		return (ft_print_error(new_env->content, new_env, str, var), 0);
	i = -1;
	str = until_equal_or_plus(new_env->content, '=');
	while (str[++i])
	{
		if (str[i] == '+' && str[i + 1] == '+')
			return (ft_print_error(new_env->content, new_env, str, var), 0);
	}
	return (free(str), 1);
}

int	add_or_change(t_env **env_list, t_list *head, char **env, t_var *var)
{
	t_env	*new_env;
	int		i;

	i = 1;
	while (head->cmd[i])
	{
		new_env = ft_lstnew_env(head->cmd[i], env);
		if (!new_env)
			return (0);
		if (!check_double_key(*env_list, new_env))
		{
			if (check_is_valid(new_env, var))
				ft_lstadd_back_env(env_list, new_env);
		}
		else
			change_the_value(env_list, new_env);
		i++;
	}
	return (1);
}

void	ft_free(t_env *head)
{
	while (head)
	{
		free(head);
		head = head->next;
	}
	free(head);
}

void	ft_only_export(t_list *head, t_env *export_list, t_var *var)
{
	if (!head->cmd[1])
		ft_print_export(export_list, var);
	ft_free(export_list);
}

int	ft_export(t_list *head, t_env **env_list, t_var *var)
{
	t_env	*help;
	t_env	*new_env_list;
	t_env	*export_list;

	help = *env_list;
	new_env_list = NULL;
	export_list = NULL;
	if (head->cmd[1])
		if (!add_or_change(env_list, head, (*env_list)->env, var))
			return (0);
	while (help)
	{
		insert(&new_env_list, help);
		help = help -> next;
	}
	while (1)
	{
		if (new_env_list == NULL)
			break ;
		help = find_small(new_env_list);
		insert(&export_list, help);
		remove_node(&new_env_list, help->content);
	}
	ft_only_export(head, export_list, var);
	return (1);
}
