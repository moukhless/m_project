/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:08:42 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/11 21:38:41 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	if (argc < 5)
	{
		write (2, "Error : Invalide argument!\n", 27);
		return (1);
	}
	else if ((ft_strcmp("here_doc", argv[1]) == 1 && argc >= 5)
		|| (ft_strcmp("here_doc", argv[1]) == 0 && argc >= 6))
	{
		exec_cmd(argv, env, argc);
		return (0);
	}
	write (2, "Error : Invalide argument!\n", 27);
	return (1);
}
