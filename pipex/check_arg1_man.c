/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg1_man.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:02:26 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/07 14:44:43 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **get_paths(char **env, char **cmd, int file)
{
    char *var;
    char *value;
    int i;
    char **paths;
    
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

char *check_cmd_is_exit(char **paths, char *cmd)
{
    int i ;
    char *path;

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

int check_path(char *path)
{
    if (access(path, X_OK) == 0)
        return (0);
    return (1);
}

char **check_cmd(char *argv, char **env, int file)
{
    char **paths;
    char **cmd;
    char *cm;
    char *str;
    
    cmd = ft_split(argv, ' ');
    if (cmd[0][0] == '/' || cmd[0][0] == '.')
        if (check_path(cmd[0]) == 0)
            return (cmd);
    if (cmd[0][0] != '/')
    {
        paths = get_paths(env, cmd, file);
        cm = ft_strjoin("/", cmd[0]);
        str = check_cmd_is_exit(paths, cm);
        if (str)
            return(return_cmd(cmd, str, paths, cm));
        free_double_p(paths);
        free(cm);
    }
    write (2 , "command not fount: ", 19);
    write (2, cmd[0], ft_strlen(cmd[0]));
    write (2, "\n", 1);
    free_double_p(cmd);
    return (NULL);
}