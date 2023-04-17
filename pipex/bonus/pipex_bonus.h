/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:11:09 by amoukhle          #+#    #+#             */
/*   Updated: 2023/04/14 01:49:42 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int ft_strlen(char *str);
int ft_strncmp(char *s1, char *s2, int n);
char	**ft_split(char *s, char c);
char	*fill_str(char **st, char *s, int start, int end);
int	num_w(char *str, char c);
int ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
int	ft_strcat(char *s1, char *s2, int i );
char **get_paths(char **env, char **cmd, int file);
char *check_cmd_is_exit(char **paths, char *cmd);
int check_path(char *path);
char **check_cmd(char *argv, char **env, int file);
int check_empty_arg(char *arg);
void free_double_p(char **str);
void exec_cmd(char **argv, char **env, int argc);
void parent_proccess(char **argv, char **env, int *fd, int num_pipe);
int open_outfile_d(char **argv);
void child_proccess(char **argv, char **env, int *fd);
int open_infile_d(char **argv);
void error_msg_p_p(char **argv, int outfile);
char **return_cmd(char **cmd, char *str, char **paths, char *cm);
void generate_multi_pipes(char **argv, char **env, int *fd, int num_pipe);
char **check_cmd_bonus(char *argv, char **env);
char **get_paths_bonus(char **env, char **cmd);

#endif