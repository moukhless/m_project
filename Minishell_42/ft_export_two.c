/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:09:31 by hachahbo          #+#    #+#             */
/*   Updated: 2023/08/03 17:04:11 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_export(t_env *export_list, t_var *var)
{
	if (!export_list)
		return ;
	while (export_list)
	{
		if (!ft_strcmp(export_list->val,
				"/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:."))
			export_list = export_list->next;
		if (export_list == NULL)
			break ;
		if (!ft_strchr(export_list->content, '='))
		{
			write(var->std_out, "declare -x ", 11);
			write(var->std_out, export_list->key, ft_strlen(export_list->key));
			write(var->std_out, "\n", 1);
		}
		else
		{
			write(var->std_out, "declare -x ", 11);
			write(var->std_out, export_list->key, ft_strlen(export_list->key));
			write(var->std_out, "=\"", 2);
			write(var->std_out, export_list->val, ft_strlen(export_list->val));
			write(var->std_out, "\"\n", 2);
		}
		export_list = export_list->next;
	}
}

void	ft_free_this(t_env *new_env, char *str)
{
	free(str);
	free(new_env->val);
	free(new_env->key);
	free(new_env->hide_path);
	free_double(new_env->env);
	free(new_env->content);
}

void	chaange_the_value_part_two(t_env *save, t_env *new_env)
{
	char	*str;

	str = NULL;
	if (new_env->plus == '+')
	{
		str = save->val;
		save->val = ft_strjoin(save->val, new_env->val);
		ft_free_this(new_env, str);
	}
	else
	{
		str = save->val;
		save->val = new_env->val;
		free(str);
		save->c = '=';
		str = save->content;
		save->content = new_env->content;
		free(str);
		free(new_env->key);
		free_double(new_env->env);
		free(new_env->hide_path);
	}
}

void	change_the_value(t_env **env_list, t_env *new_env)
{
	t_env	*save;

	save = *env_list;
	while (save)
	{
		if (!ft_strcmp(save->key, new_env->key) && new_env->c == '=')
		{
			chaange_the_value_part_two(save, new_env);
			break ;
		}
		save = save->next;
	}
	if (new_env->c != '=')
		ft_free_this(new_env, NULL);
	free(new_env);
}

void	ft_print_error(char *s, t_env *new_env, char *str, t_var *var)
{
	write(var->std_out, "export : `", 10);
	write(var->std_out, s, ft_strlen(s));
	write(var->std_out, "\': not a valid identifier\n", 26);
	g_state_exit = 1;
	free(str);
	free(new_env->key);
	free(new_env->content);
	free(new_env->val);
	free(new_env->hide_path);
	free_double(new_env->env);
	free(new_env);
}
