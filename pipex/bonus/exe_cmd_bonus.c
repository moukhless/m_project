/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:36:13 by amoukhle          #+#    #+#             */
/*   Updated: 2023/04/14 03:13:00 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void child_proccess(char **argv, char **env, int *fd)
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
    {
        close(infile);
        free(fd);
        exit (1);
    }
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

int open_outfile_d(char **argv)
{
    int outfile;
    
    outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
    if (outfile == -1)
    {
        write (2, "zsh: no such file or directory: ", 32);
        write (2, "\n", 1);
        exit (1);
    }
    return (outfile);
}

void parent_proccess(char **argv, char **env, int *fd, int num_pipe)
{
    char **cmd2;
    int outfile;
    int j;
    pid_t pid;

    pid = fork();
    if (pid == 0)
    {
        outfile = open_outfile_d(argv);
        if (!argv[num_pipe + 2][0] || check_empty_arg(argv[num_pipe + 2]) == 1)
            error_msg_p_p(argv, outfile);
        cmd2 = check_cmd(argv[num_pipe + 2], env, outfile);
        if (!cmd2)
        {
            close(outfile);
            free(fd);
            exit (1);
        }
        dup2(fd[num_pipe * 2 - 2], STDIN_FILENO);
        dup2(outfile, STDOUT_FILENO);
        close(outfile);
        j = 0;
        while (j < num_pipe * 2)
            close(fd[j++]);
        if (execve(cmd2[0], cmd2, env) == -1)
        {
            write (2, "zsh: command not found: ", 24);
            write (2, cmd2[0], ft_strlen(cmd2[0]));
            write (2, "\n", 1);
        }
        free_double_p(cmd2);
    }
}

void generate_multi_pipes(char **argv, char **env, int *fd, int num_pipe)
{
    char **cmd1;
    int i;
    int j;
    static int m;
    pid_t pid;
    static int p;
    static int a;
    int outfile;

    if (a == 0)
        a += 3;
    pid = fork();
    if (pid == 0)
    {
        if (p == num_pipe - 1)
        {
            outfile = open_outfile_d(argv);
            if (!argv[num_pipe + 2][0] || check_empty_arg(argv[num_pipe + 2]) == 1)
                error_msg_p_p(argv, outfile);
        }
        if (!argv[a][0])
            write (2, "zsh: permission denied:\n", 24);
        else if (check_empty_arg(argv[a]) == 1)
            write (2, "zsh: command not found: \n", 25);
        cmd1 = check_cmd_bonus(argv[a], env);
        if (!cmd1)
            exit (1);
        dup2(fd[m], STDIN_FILENO);
        i = m + 3;
        if (p == num_pipe - 1)
            dup2(outfile, STDOUT_FILENO);
        else
            dup2(fd[i], STDOUT_FILENO);
        m += 2;
        j = 0;
        while (j < num_pipe * 2)
            close(fd[j++]);
        if (execve(cmd1[0], cmd1, env) == -1)
        {
            write (2, "zsh: command not found : ", 24);
            write (2, cmd1[0], ft_strlen(cmd1[0]));
            write (2, "\n", 1);
        }
        free_double_p(cmd1);
        p++;
        a++;
        printf("here\n");
        if (p < num_pipe)
            generate_multi_pipes(argv, env, fd, num_pipe);
        // else
        // {
        //     printf("here\n");
        //     parent_proccess(argv, env, fd, num_pipe);
        // }
    }
}

void exec_cmd(char **argv, char **env, int argc)
{
    pid_t pid;
    int *fd;
    int num_pipe;
    int i;
    
    i = 0;
    num_pipe = argc - 4;
    fd = (int *)malloc(sizeof(int) * num_pipe * 2);
    if (!fd)
    {
        write (2, "Error: Failed to allocate memory\n", 33);
        exit (1);            
    }
    while (i < num_pipe)
    {
        if (pipe(fd + i * 2) == -1)
        {
            write (2, "Error: Failed to pipe\n", 22);
            free(fd);
            exit (1);
        }
        i++;
    }
    pid = fork();
    if (pid == -1)
    {
        write (2, "Error: Failed to fork\n", 22);
        free(fd);
        exit (1);
    }
    if (pid == 0)
    {
        child_proccess(argv, env, fd); 
        exit (0);
    }
    wait(NULL);
    generate_multi_pipes(argv, env, fd, num_pipe);
    // else
    // {
    //     wait(NULL);
    //     parent_proccess(argv, env, fd, num_pipe);
    // }
}