/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:39:47 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/08 15:39:19 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int check_path(char *path)
{
    if (access(path, X_OK) == 0)
        return (0);
    return (1);
}

int check_empty_arg(char *arg)
{
    int i;

    i = 0;
    while (arg[i] == ' ')
        i++;
    if (arg[i])
        return (0);
    return (1);
}

void free_double_p(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str[i]);
    free(str);
}

void error_msg_p_p(char **argv, int outfile)
{
    if (!argv[3][0])
        write (2, "permission denied:\n", 19);
    else 
        write (2, "command not found: \n", 20);
    close(outfile);
    exit (1);
}

char **return_cmd(char **cmd, char *str, char **paths, char *cm)
{
    free(cmd[0]);
    cmd[0] = str;
    free_double_p(paths);
    free(cm);
    return (cmd);
}