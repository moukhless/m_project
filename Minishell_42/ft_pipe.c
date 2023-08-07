/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:46:25 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/27 22:46:57 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pipe(t_var *var, int num_pipe)
{
	int	i;

	i = 0;
	while (i < num_pipe)
	{
		if (pipe(var->fd + i * 2) == -1)
		{
			write (2, "Error: Failed to pipe\n", 22);
			free(var->fd);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_num_pipe(t_list *last_list)
{
	int	n_p;

	n_p = 0;
	while (last_list)
	{
		if (last_list->type_d == PIPE_LINE)
			n_p++;
		last_list = last_list->next;
	}
	return (n_p);
}
