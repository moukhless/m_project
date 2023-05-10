/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:11:09 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/10 17:48:00 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_var
{
    int *fd;
    int infile;
    int outfile;
    int file;
    int num_cmd;
    int n_cmd;
        
} t_var;


int ft_strlen(char *str);
int ft_strncmp(char *s1, char *s2, int n);
char	**ft_split(char *s, char c);
char	*fill_str(char **st, char *s, int start, int end);
int	num_w(char *str, char c);
int ft_strcmp(char *s1, char *s2);
char	*ft_strjoin_p(char *s1, char *s2);
int	ft_strcat(char *s1, char *s2, int i );
char **get_paths(char **env, char **cmd, int file);
char *check_cmd_is_exit(char **paths, char *cmd);
int check_path(char *path);
char **check_cmd(char *argv, char **env, int file);
int check_empty_arg(char *arg);
void free_double_p(char **str);
void exec_cmd(char **argv, char **env, int argc);
int open_outfile_d(char **argv);
void child_proccess(char **argv, char **env, t_var *var);
int open_infile_d(char **argv);
void error_msg_p_p(char **argv, int outfile);
char **return_cmd(char **cmd, char *str, char **paths, char *cm);
char **check_cmd_bonus(char *argv, char **env);
char **get_paths_bonus(char **env, char **cmd);
void exec_child_p(char **argv, char **env, t_var *var, int argc);
char **do_algo(char **argv, char **env , t_var *var);
char **use_outfile(char **argv, char **env , t_var *var);
char **use_infile(char **argv, char **env, t_var *var);
void ft_pipe(t_var *var, int num_pipe);
void ft_here_doc(char **argv, char **env, t_var *var);
void ft_infile(char **argv, char **env, t_var *var);
void ft_do_algo(char **argv, char **env, t_var *var);
void ft_outfile(char **argv, char **env, t_var *var);
char **use_infile(char **argv, char **env, t_var *var);
char **use_outfile(char **argv, char **env , t_var *var);
char **use_here_doc(char **argv, char **env , t_var *var);
int open_outfile_d(char **argv);
int open_infile_d(char **argv);
char **do_algo(char **argv, char **env , t_var *var);
int open_here_doc(char **argv);
void ft_delete_here_doc(t_var *var);
void fill_file(char **argv, int fd);
void wait_childs(t_var *var);

#endif