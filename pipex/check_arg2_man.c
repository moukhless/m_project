/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg2_man.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:54:24 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/11 14:56:41 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_empty_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] == ' ')
		i++;
	if (arg[i])
		return (0);
	return (1);
}

void	free_double_p(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
}

void	error_msg_p_p(char **argv, int outfile)
{
	if (!argv[3][0])
		write (2, "permission denied:\n", 19);
	else
		write (2, "command not found: \n", 20);
	close(outfile);
	exit (1);
}

char	**return_cmd(char **cmd, char *str, char **paths, char *cm)
{
	free(cmd[0]);
	cmd[0] = str;
	free_double_p(paths);
	free(cm);
	return (cmd);
}
