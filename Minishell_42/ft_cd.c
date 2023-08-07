/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:25:45 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/31 21:05:39 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_the_path(t_env *env_list)
{
	char	*str;

	(void)env_list;
	str = getcwd(NULL, 0);
	if (!str)
	{
		printf("cd: error retrieving current directory:");
		printf(" getcwd: cannot access parent directories: ");
		printf("No such file or directory\n");
	}
	free(str);
}

int	check_home(t_env *save)
{
	while (save)
	{
		if (!ft_strcmp(save->key, "HOME"))
			return (1);
		save = save->next;
	}
	return (0);
}

void	check_cd_one_case(t_env **env_list, t_list *head)
{
	t_env	*save;
	char	*str;

	str = NULL;
	save = *env_list;
	if (!check_home(save))
	{
		if (!head->cmd[1])
			printf("bash: cd: HOME not set\n");
		else if (!ft_strcmp(head ->cmd[1], "~"))
			cd_change_pwd(env_list, "/Users/hachahbo");
	}
	else
	{
		while (save)
		{
			if (!ft_strcmp(save->key, "HOME"))
			{
				str = save->val;
				break ;
			}
			save = save->next;
		}
		cd_change_pwd(env_list, str);
	}
}

int	ft_check_args_of_cd(t_list *head, t_env **env_list)
{
	if (!head->cmd[1] || !ft_strcmp(head ->cmd[1], "~"))
		check_cd_one_case(env_list, head);
	else if (!ft_strcmp(head->cmd[1], ".."))
	{
		cd_change_pwd(env_list, head->cmd[1]);
		check_the_path(*env_list);
	}
	else if (!ft_strcmp(head->cmd[1], "."))
		cd_change_pwd(env_list, head->cmd[1]);
	else if (!ft_strcmp(head->cmd[1], "/"))
		cd_change_pwd(env_list, head->cmd[1]);
	else
		cd_change_pwd(env_list, head->cmd[1]);
	return (0);
}

int	rendering_cd(t_list *list, t_env **env_list)
{
	if (list == NULL)
		return (0);
	ft_check_args_of_cd(list, env_list);
	return (0);
}
