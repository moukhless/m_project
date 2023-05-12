/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_man.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:39:35 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/11 15:12:30 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipe_m(int fd[])
{
	if (pipe(fd) == -1)
	{
		write (2, "Error: Failed to pipe\n", 22);
		exit (1);
	}
}

int	main(int argc, char **argv, char **env)
{
	if (argc == 5)
	{
		exec_cmd(argv, env);
		return (0);
	}
	write (2, " Error : Invalide argument!\n", 28);
	return (1);
}
