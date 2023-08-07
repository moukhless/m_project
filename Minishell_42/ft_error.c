/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:37:07 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/27 22:58:49 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_isdir(char **cmd)
{
	DIR	*dir;

	dir = opendir(cmd[0]);
	if (dir)
	{
		write (2, "bash: ", 6);
		write (2, cmd[0], ft_strlen(cmd[0]));
		write (2, ": is a directory\n", 17);
		closedir(dir);
		exit (126);
	}
}

void	error_cmd(char **cmd)
{
	int	len_error;

	len_error = ft_strlen(strerror(errno));
	write(2, "bash: ", 6);
	write (2, cmd[0], ft_strlen(cmd[0]));
	write (2, ": ", 2);
	write(2, strerror(errno), len_error);
	write (2, "\n", 1);
	exit (127);
}

void	error_fork(void)
{
	write (2, "Error: Failed to fork\n", 22);
	exit (1);
}

void	affiche_error(void)
{
	perror("Error: malloc");
	exit (1);
}
