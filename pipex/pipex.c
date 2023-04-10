/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:39:35 by amoukhle          #+#    #+#             */
/*   Updated: 2023/04/10 01:14:46 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env)
{    
    int infile;
    int outfile;

    if (argc == 5)
    {
        outfile = open_outfile_d(argv);
        infile = open_infile_d(argv);
        exec_cmd(argv, env, infile, outfile);
        return (0);
    }
    write (2, " Error : Invalide argument!\n", 28);
    return (1);
}



