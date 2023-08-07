/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:13:17 by hachahbo          #+#    #+#             */
/*   Updated: 2023/08/03 16:45:45 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_after_exit(t_list *head)
{
	int	i;

	i = 1;
	while (head->cmd[i])
	{
		if (i > 1)
		{
			printf("bash: exit: too many arguments\n");
			return (0);
		}
		i++;
	}
	i = 1;
	while (head->cmd[1][i])
	{
		if (!ft_isdigit(head->cmd[1][i]))
		{
			printf("bash: exit: %s: numeric argument required", head->cmd[1]);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_exit(t_list *list)
{
	unsigned char		x;
	unsigned long long	a;

	x = 0;
	a = 0;
	printf("exit\n");
	if (list->cmd[1])
	{
		if (ft_check_after_exit(list))
			a = ft_atoi(list->cmd[1]);
		if (a > 9223372036854775807)
			printf("bash: exit: %s: numeric argument required", list->cmd[1]);
		x = a;
	}
	exit(x);
}

int	ft_builtins(t_list *list, t_env **env_list, t_var *var)
{
	if (!ft_strcmp(list->cmd[0], "cd")
		|| !ft_strcmp(list->cmd[0], "/usr/bin/cd"))
		rendering_cd(list, env_list);
	else if (!ft_strcmp(list->cmd[0], "pwd") 
		|| !ft_strcmp(list->cmd[0], "/bin/pwd"))
		ft_pwd(*env_list, var);
	else if (!ft_strcmp(list->cmd[0], "echo") 
		|| !ft_strcmp(list->cmd[0], "/bin/echo"))
		ft_echo(list, var);
	else if (!ft_strcmp(list->cmd[0], "env") 
		|| !ft_strcmp(list->cmd[0], "/usr/bin/env"))
		ft_env(*env_list, var);
	else if (!ft_strcmp(list->cmd[0], "unset"))
		ft_unset(list, env_list, var);
	else if (!ft_strcmp(list->cmd[0], "export"))
		ft_export(list, env_list, var);
	else if (!ft_strcmp(list->cmd[0], "exit"))
		ft_exit(list);
	else
		return (1);
	return (0);
}

int	ft_is_builting_cmd(t_list *last_list, t_var *var)
{
	if (ft_serche_in_list(last_list, "/usr/bin/cd") == 0
		|| ft_serche_in_list(last_list, "cd") == 0
		|| ft_serche_in_list(last_list, "/bin/pwd") == 0
		|| ft_serche_in_list(last_list, "pwd") == 0
		|| ft_serche_in_list(last_list, "/usr/bin/env") == 0
		|| ft_serche_in_list(last_list, "env") == 0
		|| ft_serche_in_list(last_list, "/bin/echo") == 0
		|| ft_serche_in_list(last_list, "echo") == 0
		|| ft_serche_in_list(last_list, "unset") == 0
		|| ft_serche_in_list(last_list, "export") == 0
		|| ft_serche_in_list(last_list, "exit") == 0)
	{
		var->is_built = 1;
		return (0);
	}
	return (1);
}
