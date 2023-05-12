/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:46:24 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/11 15:59:22 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_delete_here_doc(t_var *var)
{
	int	status;

	status = unlink("/tmp/here_doc");
	if (status == -1)
	{
		perror("Error deleting file");
		free(var->fd);
		free(var);
		exit (1);
	}
}

void	ft_here_doc(char **argv, char **env, t_var *var)
{
	char	**cmd;
	int		j;
	int		len_error;

	if (var->file == -1)
		exit(1);
	cmd = use_here_doc(argv, env, var);
	dup2(var->file, STDIN_FILENO);
	dup2(var->fd[1], STDOUT_FILENO);
	close(var->file);
	j = 0;
	while (j < (var->n_cmd - 1) * 2)
		close(var->fd[j++]);
	if (execve(cmd[0], cmd, env) == -1)
	{
		len_error = ft_strlen(strerror(errno));
		write(2, strerror(errno), len_error);
		write (2, ": ", 2);
		write (2, cmd[0], ft_strlen(cmd[0]));
		write (2, "\n", 1);
		exit (1);
	}
	free_double_p(cmd);
	exit (0);
}

void	ft_infile(char **argv, char **env, t_var *var)
{
	char	**cmd;
	int		j;
	int		len_error;

	var->infile = open_infile_d(argv);
	cmd = use_infile(argv, env, var);
	dup2(var->infile, STDIN_FILENO);
	dup2(var->fd[1], STDOUT_FILENO);
	close(var->infile);
	j = 0;
	while (j < (var->n_cmd - 1) * 2)
		close(var->fd[j++]);
	if (execve(cmd[0], cmd, env) == -1)
	{
		len_error = ft_strlen(strerror(errno));
		write(2, strerror(errno), len_error);
		write (2, ": ", 2);
		write (2, cmd[0], ft_strlen(cmd[0]));
		write (2, "\n", 1);
		exit (1);
	}
	free_double_p(cmd);
	exit (0);
}

void	ft_outfile(char **argv, char **env, t_var *var)
{
	char	**cmd;
	int		j;
	int		len_error;

	var->outfile = open_outfile_d(argv);
	cmd = use_outfile(argv, env, var);
	dup2(var->fd[(var->num_cmd - 1) * 2], STDIN_FILENO);
	dup2(var->outfile, STDOUT_FILENO);
	close(var->outfile);
	j = 0;
	while (j < (var->n_cmd - 1) * 2)
		close(var->fd[j++]);
	if (execve(cmd[0], cmd, env) == -1)
	{
		len_error = ft_strlen(strerror(errno));
		write(2, strerror(errno), len_error);
		write (2, ": ", 2);
		write (2, cmd[0], ft_strlen(cmd[0]));
		write (2, "\n", 1);
		exit (1);
	}
	free_double_p(cmd);
	exit (0);
}

void	ft_do_algo(char **argv, char **env, t_var *var)
{
	char	**cmd;
	int		j;
	int		len_error;

	cmd = do_algo(argv, env, var);
	dup2(var->fd[(var->num_cmd - 1) * 2], STDIN_FILENO);
	dup2(var->fd[(var->num_cmd - 1) * 2 + 3], STDOUT_FILENO);
	j = 0;
	while (j < (var->n_cmd - 1) * 2)
		close(var->fd[j++]);
	if (execve(cmd[0], cmd, env) == -1)
	{
		len_error = ft_strlen(strerror(errno));
		write(2, strerror(errno), len_error);
		write (2, ": ", 2);
		write (2, cmd[0], ft_strlen(cmd[0]));
		write (2, "\n", 1);
		exit (1);
	}
	free_double_p(cmd);
	exit (0);
}
