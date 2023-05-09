/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:36:13 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/09 23:56:21 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void child_proccess(char **argv, char **env, t_var *var)
{
    if (var->num_cmd == 0 && ft_strcmp("here_doc", argv[1]) == 0)
        ft_here_doc(argv, env, var);
    else if (var->num_cmd == 0)
        ft_infile(argv, env, var);
    else if (var->num_cmd == var->n_cmd - 1)
        ft_outfile(argv, env, var);
    else
        ft_do_algo(argv, env, var);
}

void exec_child_p(char **argv, char **env, t_var *var, int argc)
{
    pid_t pid;
    
    var->n_cmd = argc - 3;
    var->num_cmd = 0;
    if (ft_strcmp("here_doc", argv[1]) == 0)
        var->n_cmd -= 1;
    if (ft_strcmp("here_doc", argv[1]) == 0)
        var->file = open_here_doc(argv);
    while (var->num_cmd < var->n_cmd)
    {
        pid = fork();
        if (pid == -1)
        {
            write (2, "Error: Failed to fork\n", 22);
            exit (1);
        }
        if (pid == 0)
            child_proccess(argv, env, var);
        (var->num_cmd)++;
    }
    wait(NULL);
}

void exec_cmd(char **argv, char **env, int argc)
{
    int num_pipe;
    t_var *var;
    
    var = (t_var*)malloc(sizeof(t_var));
    num_pipe = argc - 4;
    if (ft_strcmp("here_doc", argv[1]) == 0)
        num_pipe -= 1;
    var->fd = (int *)malloc(sizeof(int) * num_pipe * 2);
    if (!(var->fd))
    {
        write (2, "Error: Failed to allocate memory\n", 33);
        exit (1);            
    }
    ft_pipe(var, num_pipe);
    exec_child_p(argv, env, var, argc);
    ft_delete_here_doc(var);
    free(var->fd);
    free(var);
}