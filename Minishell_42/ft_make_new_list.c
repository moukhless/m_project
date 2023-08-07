/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_new_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:06:26 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/29 18:21:33 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_make_new_list(t_list *head, t_list **new_list, t_env *env_list)
{
	t_var		var;
	t_list_str	*list_str;

	list_str = NULL;
	var.env_list = env_list;
	while (head)
	{
		var.num_env = 0;
		var.in_join = 0;
		var.str = NULL;
		if (is_word(head))
			var.str = head->content;
		while (head && !join_node(head))
		{
			creat_word(head, new_list, &list_str, &var);
			head = head->next;
			var.in_join = 1;
		}
		if (var.str)
			add_node(new_list, var.str, var.in_join);
		if (var.in_join == 0 && head)
			head = head->next;
	}
	list_strclear(&list_str);
}

void	creat_word(t_list *head, t_list **new_list,
				t_list_str	**list_str, t_var *var)
{
	char	*tmp;

	var->skip = 0;
	if (!skip_node(head, var->num_env))
		ft_skip_node(var, head);
	if (!var->skip && head->type == ENV)
	{
		var->num_env++;
		tmp = handle_env(head, var->env_list, var->num_env);
		if (!tmp)
		{
			var->in_join = 1;
			var->skip = 1;
		}
		if (!var->skip && head->state == GENERAL && ft_strcmp(tmp, "$"))
			var->str = generate_value_of_env(var->str, tmp, list_str, new_list);
		else if (!var->skip)
		{
			var->str = join_list_str(var->str, tmp, list_str);
			free(tmp);
		}
	}
	else if (!var->skip)
		var->str = join_list_str(var->str, head->content, list_str);
}

char	*join_list_str(char *s1, char *s2, t_list_str **list_str)
{
	s1 = ft_strjoin(s1, s2);
	list_stradd_back(list_str, new_list_str(s1, 0));
	return (s1);
}
