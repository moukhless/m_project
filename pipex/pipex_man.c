/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_man.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:39:35 by amoukhle          #+#    #+#             */
/*   Updated: 2023/04/12 23:36:22 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env)
{    
    if (argc == 5)
    {
        exec_cmd(argv, env);
        return (0);
    }
    write (2, " Error : Invalide argument!\n", 28);
    return (1);
}



