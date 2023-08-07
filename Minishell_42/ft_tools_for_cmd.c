/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_for_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:39:02 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/27 22:41:04 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_serche_for_cmd(t_list **last_list)
{
	while (*last_list && (*last_list)->type_d != PIPE_LINE)
	{
		if ((*last_list)->type_d == WORD)
			return ;
		*last_list = (*last_list)->next;
	}
}

char	*check_cmd_is_exit(char **paths, char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], cmd);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	**check_cmd(t_list *last_list, t_env *env_list)
{
	char	**paths;
	char	**cmd;
	char	*cm;
	char	*str;

	cmd = last_list->cmd;
	if (cmd[0][0] == '/' || cmd[0][0] == '.')
		return (cmd);
	if (ft_strcmp(cmd[0], ""))
	{
		paths = get_paths(env_list, cmd);
		cm = ft_strjoin("/", cmd[0]);
		str = check_cmd_is_exit(paths, cm);
		if (str)
			return (return_cmd(cmd, str, paths, cm));
		free_double(paths);
		free(cm);
	}
	write (2, "bash: ", 6);
	write (2, cmd[0], ft_strlen(cmd[0]));
	write (2, ": command not found\n", 20);
	return (NULL);
}

char	**return_cmd(char **cmd, char *str, char **paths, char *cm)
{
	free(cmd[0]);
	cmd[0] = str;
	free_double(paths);
	free(cm);
	return (cmd);
}

char	**get_paths(t_env *env_list, char **cmd)
{
	char	*var;
	char	*value;
	char	**paths;
	t_env	*tmp;

	var = "PATH";
	tmp = env_list;
	value = NULL;
	while (env_list)
	{
		if (ft_strncmp(var, env_list->content, ft_strlen(var)) == 0)
			value = &env_list->content[ft_strlen(var) + 1];
		env_list = env_list->next;
	}
	if (!value)
		value = tmp->hide_path;
	if (!value)
	{
		write (2, "bash: ", 6);
		write (2, cmd[0], ft_strlen(cmd[0]));
		write (2, ": command not found\n", 20);
		exit (127);
	}
	paths = ft_split(value, ':');
	return (paths);
}
