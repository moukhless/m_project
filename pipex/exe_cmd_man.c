/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:23:08 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/10 17:43:20 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_redirection_c(int fd[], int infile)
{
    close(fd[0]);
    dup2(infile, STDIN_FILENO);
    close(infile);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
}

void child_proccess_1(char **argv, char **env, int fd[])
{
    char **cmd1;
    int infile;
    int len_error;
    
    infile = open_infile_d(argv);
    if (!argv[2][0] || check_empty_arg(argv[2]) == 1)
        error_msg_c_p(argv, infile);
    cmd1 = check_cmd(argv[2], env, infile);
    if (!cmd1)
    {
        close(infile);
        exit (1);
    }
    ft_redirection_c(fd, infile);
    if (execve(cmd1[0], cmd1, env) == -1)
    {
        len_error = ft_strlen(strerror(errno));
        write(2, strerror(errno), len_error);
        write (2, ": ", 2);
        write (2, cmd1[0], ft_strlen(cmd1[0]));
        write (2, "\n", 1);
    }
    free_double_p(cmd1);
    exit (0);
}

void ft_redirection_p(int fd[], int outfile)
{
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    dup2(outfile, STDOUT_FILENO);
    close(fd[0]);
    close(outfile);
}
void child_proccess_2(char **argv, char **env, int fd[])
{
    char **cmd2;
    int outfile;
    int len_error;

    outfile = open_outfile_d(argv);
    if (!argv[3][0] || check_empty_arg(argv[3]) == 1)
        error_msg_p_p(argv, outfile);
    cmd2 = check_cmd(argv[3], env, outfile);
    if (!cmd2)
    {
        close(outfile);
        exit (1);
    }
    ft_redirection_p(fd, outfile);
    if (execve(cmd2[0], cmd2, env) == -1)
    {
        len_error = ft_strlen(strerror(errno));
        write(2, strerror(errno), len_error);
        write (2, ": ", 2);
        write (2, cmd2[0], ft_strlen(cmd2[0]));
        write (2, "\n", 1);
    }
    free_double_p(cmd2);
}

void exec_cmd(char **argv, char **env)
{
    pid_t pid1;
    pid_t pid2;
    int fd[2];
    
    ft_pipe_m(fd);
    pid1 = fork();
    if (pid1 == -1)
    {
        write (2, "Error: Failed to fork\n", 22);
        exit (1);
    }
    if (pid1 == 0)
        child_proccess_1(argv, env, fd);
    pid2 = fork();
    if (pid2 == -1)
    {
        write (2, "Error: Failed to fork\n", 22);
        exit (1);
    }
    if (pid2 == 0)
        child_proccess_2(argv, env, fd);
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}