/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:44:16 by amoukhle          #+#    #+#             */
/*   Updated: 2023/08/02 19:29:52 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_childs(t_var *var, pid_t last_child)
{
	int		j;
	int		state;
	pid_t	pid;

	(void)last_child;
	j = 0;
	while (j < (var->n_cmd - 1) * 2)
		close(var->fd[j++]);
	j = 0;
	while (j < var->n_cmd)
	{
		pid = wait(&state);
		if (pid == last_child)
			set_state_exit(state);
		j++;
	}
}

void	set_state_exit(int state)
{
	if (WIFEXITED(state))
		g_state_exit = WEXITSTATUS(state);
	else if (WIFSIGNALED(state))
	{
		g_state_exit = WTERMSIG(state);
		if (g_state_exit == 3)
			g_state_exit = 131;
		else if (g_state_exit == 2)
			g_state_exit = 130;
		else if (g_state_exit == 11)
			g_state_exit = 0;
	}
}

void	ft_wait(t_var *var, pid_t last_child, t_list_str **list_heredoce)
{
	t_list_str	*tmp;

	tmp = *list_heredoce;
	while (tmp)
	{
		close(tmp->fd);
		tmp = tmp->next;
	}
	wait_childs(var, last_child);
	list_strclear(list_heredoce);
}
