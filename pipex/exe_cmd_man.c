/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:23:08 by amoukhle          #+#    #+#             */
/*   Updated: 2023/04/15 18:43:31 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int open_infile_d(char **argv)
{
    int infile;
    int len;
    
    if (argv[1][0])
        len = ft_strlen(argv[1]);
    infile = open(argv[1], O_RDONLY, 0777);
    if (infile == -1)
    {
        write (2, "zsh: no such file or directory: ", 32);
        if (argv[1][0])
            write (2, argv[1], len);
        write (2, "\n", 1);
        exit (1);
    }
    return (infile);
}

void child_proccess(char **argv, char **env, int fd[])
{
    char **cmd1;
    int infile;
    
    infile = open_infile_d(argv);
    if (!argv[2][0])
        write (2, "zsh: permission denied:\n", 24);
    else if (check_empty_arg(argv[2]) == 1)
        write (2, "zsh: command not found: \n", 25);
    cmd1 = check_cmd(argv[2], env, infile);
    if (!cmd1)
        exit (1);
    close(fd[0]);
    dup2(infile, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(infile);
    close(fd[1]);
    if (execve(cmd1[0], cmd1, env) == -1)
    {
        write (2, "zsh: command not found : ", 24);
        write (2, cmd1[0], ft_strlen(cmd1[0]));
        write (2, "\n", 1);
    }
    free_double_p(cmd1);
}

int error_msgs(char *str)
{
    int i;
    int p;

    p = 0;
    i = 0;
    while (str[i])
    {
        if (str[0] == '.')
        {
            if (str[i++] == '.')
                p++;
            else
                break;
        }
        if (str[0] == '/')
        {
            
        }
    }
    if (p <= 2)
        return (0);
    else if (p == 3)
        return (3);
    else
        return (1);
    if (!str[i] && i == 0)
        return (1);
    return (0);
}

int open_outfile_d(char **argv)
{
    int outfile;
    
    outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
    if (outfile == -1)
    {
        if (error_msgs(argv[4]) == 0)
            write (2, "zsh: is a directory: ", 21);
        else if (error_msgs(argv[4]) == 2)
            write (2, "zsh: permission denied: ", 24);
        else if (error_msgs(argv[4]) == 3)
            write (2, "zsh: not a directory: ", 22);
        else 
            write (2, "zsh: no such file or directory: ", 32);
        if (argv[4])
            write (2, argv[4], ft_strlen(argv[4]));
        write (2, "\n", 1);
        exit (1);
    }
    return (outfile);
}

void parent_proccess(char **argv, char **env, int fd[])
{
    char **cmd2;
    int outfile;

    outfile = open_outfile_d(argv);
    if (!argv[3][0] || check_empty_arg(argv[3]) == 1)
        error_msg_p_p(argv, outfile);
    cmd2 = check_cmd(argv[3], env, outfile);
    if (!cmd2)
    {
        close(outfile);
        exit (1);
    }
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    dup2(outfile, STDOUT_FILENO);
    close(fd[0]);
    close(outfile);
    if (execve(cmd2[0], cmd2, env) == -1)
    {
        write (2, "zsh: command not found: ", 24);
        write (2, cmd2[0], ft_strlen(cmd2[0]));
        write (2, "\n", 1);
    }
    free_double_p(cmd2);
}

void exec_cmd(char **argv, char **env)
{
    pid_t pid;
    int fd[2];
    
    if (pipe(fd) == -1)
    {
        write (2, "Error: Failed to pipe\n", 22);
        exit (1);
    }
    pid = fork();
    if (pid == -1)
    {
        write (2, "Error: Failed to fork\n", 22);
        exit (1);
    }
    if (pid == 0)
        child_proccess(argv, env, fd);
    else
    {
        wait(NULL);
        parent_proccess(argv, env, fd);
    }
}