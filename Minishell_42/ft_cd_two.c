/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 09:59:51 by hachahbo          #+#    #+#             */
/*   Updated: 2023/08/03 17:00:13 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	inside_change_the_pwd(t_env *save)
{
	char	*str;
	char	*help;

	help = save->val;
	str = getcwd(NULL, 0);
	if (!str)
	{
		save->val = ft_strjoin(save->val, "/..");
		save->c = '=';
		free(save->content);
		save->content = ft_strjoin("PWD=", save->val);
		free(help);
	}
	else
	{
		save->val = getcwd(NULL, 0);
		save->c = '=';
		free(save->content);
		save->content = ft_strjoin("PWD=", save->val);
		free(help);
	}
	free(str);
}

void	change_the_pwd(t_env **env_list)
{
	t_env	*save;

	save = *env_list;
	while (save)
	{
		if (!ft_strcmp(save->key, "PWD"))
			inside_change_the_pwd(save);
		save = save->next;
	}
}

void	change_the_oldpwd(t_env **env_list)
{
	t_env	*save;
	char	*str;
	char	*str2;
	char	*help;

	save = *env_list;
	while (save)
	{
		if (!ft_strcmp(save->key, "OLDPWD"))
		{
			str2 = getcwd(NULL, 0);
			help = ft_strjoin("=", str2);
			str = ft_strjoin("OLDPWD", help);
			free(help);
			free(str2);
			help = save->content;
			save->content = str;
			free(help);
			help = save->val;
			save->val = getcwd(NULL, 0);
			save->c = '=';
			free(help);
		}
		save = save->next;
	}
}

void	cd_change_pwd(t_env **env_list, char *str)
{
	change_the_oldpwd(env_list);
	if (chdir(str) == -1)
	{
		write (2, "bash: cd: ", 11);
		write (2, str, ft_strlen(str));
		write (2, ": No such file or directory\n", 28);
		g_state_exit = 1;
	}
	change_the_pwd(env_list);
}
