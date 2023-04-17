/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:08:42 by amoukhle          #+#    #+#             */
/*   Updated: 2023/04/13 00:04:19 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int main(int argc, char **argv, char **env)
{    
    if (argc >= 5)
    {
        exec_cmd(argv, env, argc);
        return (0);
    }
    write (2, "Error : Invalide argument!\n", 27);
    return (1);
}