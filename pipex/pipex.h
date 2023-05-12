/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:55:42 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/11 15:14:56 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, int n);
char	**ft_split(char *s, char c);
char	*fill_str(char **st, char *s, int start, int end);
int		num_w(char *str, char c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strcat(char *s1, char *s2, int i );
char	**get_paths(char **env, char **cmd, int file);
char	*check_cmd_is_exit(char **paths, char *cmd);
int		check_path(char *path);
char	**check_cmd(char *argv, char **env, int file);
int		check_empty_arg(char *arg);
void	free_double_p(char **str);
void	exec_cmd(char **argv, char **env);
void	child_proccess_2(char **argv, char **env, int fd[]);
int		open_outfile_d(char **argv);
void	child_proccess_1(char **argv, char **env, int fd[]);
int		open_infile_d(char **argv);
void	error_msg_p_p(char **argv, int outfile);
void	error_msg_c_p(char **argv, int infile);
char	**return_cmd(char **cmd, char *str, char **paths, char *cm);
void	ft_pipe_m(int fd[]);

#endif
