/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:39:10 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/11 15:22:18 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**get_paths(char **env, char **cmd, int file)
{
	char	*var;
	char	*value;
	int		i;
	char	**paths;

	var = "PATH";
	value = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(var, env[i], ft_strlen(var)) == 0)
			value = &env[i][ft_strlen(var) + 1];
		i++;
	}
	if (!value)
	{
		write (2, "command not found: ", 19);
		write (2, cmd[0], ft_strlen(cmd[0]));
		write (2, "\n", 1);
		free_double_p(cmd);
		close(file);
		exit (1);
	}
	paths = ft_split(value, ':');
	return (paths);
}

char	**get_paths_bonus(char **env, char **cmd)
{
	char	*var;
	char	*value;
	int		i;
	char	**paths;

	var = "PATH";
	value = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(var, env[i], ft_strlen(var)) == 0)
			value = &env[i][ft_strlen(var) + 1];
		i++;
	}
	if (!value)
	{
		write (2, "command not found: ", 19);
		write (2, cmd[0], ft_strlen(cmd[0]));
		write (2, "\n", 1);
		free_double_p(cmd);
		exit (1);
	}
	paths = ft_split(value, ':');
	return (paths);
}

char	*check_cmd_is_exit(char **paths, char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin_p(paths[i], cmd);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	**check_cmd(char *argv, char **env, int file)
{
	char	**paths;
	char	**cmd;
	char	*cm;
	char	*str;

	cmd = ft_split(argv, ' ');
	if (cmd[0][0] == '/' || cmd[0][0] == '.')
		if (check_path(cmd[0]) == 0)
			return (cmd);
	if (cmd[0][0] != '/')
	{
		paths = get_paths(env, cmd, file);
		cm = ft_strjoin_p("/", cmd[0]);
		str = check_cmd_is_exit(paths, cm);
		if (str)
			return (return_cmd(cmd, str, paths, cm));
		free_double_p(paths);
		free(cm);
	}
	write (2, "command not found: ", 19);
	write (2, cmd[0], ft_strlen(cmd[0]));
	write (2, "\n", 1);
	free_double_p(cmd);
	return (NULL);
}

char	**check_cmd_bonus(char *argv, char **env)
{
	char	**paths;
	char	**cmd;
	char	*cm;
	char	*str;

	cmd = ft_split(argv, ' ');
	if (cmd[0][0] == '/' || cmd[0][0] == '.')
		if (check_path(cmd[0]) == 0)
			return (cmd);
	if (cmd[0][0] != '/')
	{
		paths = get_paths_bonus(env, cmd);
		cm = ft_strjoin_p("/", cmd[0]);
		str = check_cmd_is_exit(paths, cm);
		if (str)
			return (return_cmd(cmd, str, paths, cm));
		free_double_p(paths);
		free(cm);
	}
	write (2, "command not found: ", 19);
	write (2, cmd[0], ft_strlen(cmd[0]));
	write (2, "\n", 1);
	free_double_p(cmd);
	return (NULL);
}
