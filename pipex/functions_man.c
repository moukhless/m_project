/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_man.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:51:27 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/11 15:10:41 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		len_error = ft_strlen(strerror(errno));
		write(2, strerror(errno), len_error);
		write (2, ": ", 2);
		if (argv[4])
			write (2, argv[4], ft_strlen(argv[4]));
		write (2, "\n", 1);
		exit (1);
	}
	return (outfile);
}

void	error_msg_c_p(char **argv, int infile)
{
	if (!argv[2][0])
		write (2, "permission denied:\n", 19);
	else
		write (2, "command not found: \n", 20);
	close(infile);
	exit (1);
}
