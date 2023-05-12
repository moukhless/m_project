/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:55:53 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/11 15:59:37 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	fill_file(char **argv, int fd)
{
	char	*line;
	char	*arg;

	while (1)
	{
		write (1, "here_doc> ", 10);
		line = get_next_line(STDIN_FILENO);
		arg = ft_strjoin_p(argv[2], "\n");
		if (!line)
		{
			free(arg);
			break ;
		}
		if (ft_strcmp(arg, line) == 0)
		{
			free(line);
			free(arg);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
		free(arg);
	}
	close (fd);
}

int	open_here_doc(char **argv)
{
	int	file;
	int	len_error;

	file = open("/tmp/here_doc", O_WRONLY | O_CREAT, 0777);
	if (file == -1)
	{
		len_error = ft_strlen(strerror(errno));
		write(2, strerror(errno), len_error);
		write (2, ": ", 2);
		if (argv[1])
			write (2, argv[1], ft_strlen(argv[1]));
		write (2, "\n", 1);
	}
	fill_file(argv, file);
	file = open("/tmp/here_doc", O_RDONLY, 0777);
	if (file == -1)
	{
		len_error = ft_strlen(strerror(errno));
		write(2, strerror(errno), len_error);
		write (2, ": ", 2);
		if (argv[1])
			write (2, argv[1], ft_strlen(argv[1]));
		write (2, "\n", 1);
	}
	return (file);
}

char	**do_algo(char **argv, char **env, t_var *var)
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
	cmd = check_cmd_bonus(argv[var->num_cmd + p], env);
	if (!cmd)
	{
		free(var->fd);
		free(var);
		exit (1);
	}
	return (cmd);
}

void	ft_pipe(t_var *var, int num_pipe)
{
	int	i;

	i = 0;
	while (i < num_pipe)
	{
		if (pipe(var->fd + i * 2) == -1)
		{
			write (2, "Error: Failed to pipe\n", 22);
			free(var->fd);
			free(var);
			exit (1);
		}
		i++;
	}
}
