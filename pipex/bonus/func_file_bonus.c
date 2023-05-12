/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:52:13 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/11 15:37:43 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**use_here_doc(char **argv, char **env, t_var *var)
{
	char	**cmd;

	if (!argv[var->num_cmd + 3][0])
		write (2, "permission denied:\n", 19);
	else if (check_empty_arg(argv[var->num_cmd + 3]) == 1)
		write (2, "command not found: \n", 20);
	cmd = check_cmd(argv[var->num_cmd + 3], env, var->file);
	if (!cmd)
	{
		free(var->fd);
		free(var);
		exit (1);
	}
	return (cmd);
}

char	**use_outfile(char **argv, char **env, t_var *var)
{
	char	**cmd;
	int		p;

	p = 2;
	if (ft_strcmp("here_doc", argv[1]) == 0)
		p = 3;
	if (!argv[var->num_cmd + p][0])
		write (2, "permission denied:\n", 19);
	else if (check_empty_arg(argv[var->num_cmd + p]) == 1)
		write (2, "command not found: \n", 20);
	cmd = check_cmd(argv[var->num_cmd + p], env, var->outfile);
	if (!cmd)
	{
		close(var->outfile);
		free(var->fd);
		exit (1);
	}
	return (cmd);
}

char	**use_infile(char **argv, char **env, t_var *var)
{
	char	**cmd;

	if (!argv[var->num_cmd + 2][0])
		write (2, "permission denied:\n", 19);
	else if (check_empty_arg(argv[var->num_cmd + 2]) == 1)
		write (2, "command not found: \n", 20);
	cmd = check_cmd(argv[var->num_cmd + 2], env, var->infile);
	if (!cmd)
	{
		close(var->infile);
		free(var->fd);
		exit (1);
	}
	return (cmd);
}

int	open_infile_d(char **argv)
{
	int	infile;
	int	len;
	int	len_error;

	if (argv[1][0])
	len = ft_strlen(argv[1]);
	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
	{
		len_error = ft_strlen(strerror(errno));
		write(2, strerror(errno), len_error);
		write (2, ": ", 2);
		if (argv[1][0])
			write (2, argv[1], len);
		write (2, "\n", 1);
		exit (1);
	}
	return (infile);
}

int	open_outfile_d(char **argv)
{
	int	outfile;
	int	len_error;
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (ft_strcmp("here_doc", argv[1]) == 0)
		outfile = open(argv[i - 1], O_RDWR | O_CREAT | O_APPEND, 0777);
	else
		outfile = open(argv[i - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		len_error = ft_strlen(strerror(errno));
		write(2, strerror(errno), len_error);
		write (2, ": ", 2);
		if (argv[i - 1])
			write (2, argv[i - 1], ft_strlen(argv[i - 1]));
		write (2, "\n", 1);
		exit (1);
	}
	return (outfile);
}
