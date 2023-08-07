/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:29:59 by amoukhle          #+#    #+#             */
/*   Updated: 2023/08/03 17:07:22 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execution(t_list *last_list, t_env **env_list, t_var *var)
{
	int	num_pipe;

	num_pipe = ft_num_pipe(last_list);
	if (num_pipe != 0)
	{
		var->fd = (int *)malloc(sizeof(int) * num_pipe * 2);
		if (!(var->fd))
			affiche_error();
		if (ft_pipe(var, num_pipe) == 1)
			return ;
	}
	exec_child(last_list, env_list, var, num_pipe);
	if (num_pipe != 0)
		free(var->fd);
}

void	ft_position_start_end(t_list **last_list,
			t_list_str **list_heredoce_tmp)
{
	while (*last_list && (*last_list)->type_d != PIPE_LINE)
	{
		if ((*last_list)->type_d == HERE_DOC)
			*list_heredoce_tmp = (*list_heredoce_tmp)->next;
		*last_list = (*last_list)->next;
	}
	if (*last_list && (*last_list)->type_d == PIPE_LINE)
		*last_list = (*last_list)->next;
}

pid_t	ft_fork(t_var *var, t_list **list,
			t_list_str **list_heredoce_tmp, t_env **env_list)
{
	pid_t	pid;

	while (var->num_cmd < var->n_cmd)
	{
		if (ft_serche_in_list(*list, "./minishell") == 0)
			signal(SIGINT, nothing_minishell);
		else
		{
			signal(SIGINT, nothing);
			signal(SIGQUIT, nothing);
		}
		pid = fork();
		if (pid == -1)
			error_fork();
		if (pid == 0)
			ft_child_proccess(*list, env_list, var, list_heredoce_tmp);
		(var->num_cmd)++;
		ft_position_start_end(list, list_heredoce_tmp);
	}
	return (pid);
}

void	exec_child(t_list *last_list, t_env **env_list,
				t_var *var, int num_pipe)
{
	t_list		*list;
	t_list_str	*list_heredoce;
	t_list_str	*list_heredoce_tmp;
	pid_t		last_child;

	list = last_list;
	list_heredoce = NULL;
	init_var(var, num_pipe);
	ft_serche_for_heredoce(last_list, var, &list_heredoce);
	if (get_value(-1) == 4)
	{
		list_strclear(&list_heredoce);
		return ;
	}
	list_heredoce_tmp = list_heredoce;
	if (var->n_cmd == 1 && ft_is_builting_cmd(last_list, var) == 0)
	{
		ft_serche_for_doc(last_list, *env_list, var, &list_heredoce);
		ft_serche_for_cmd(&last_list);
		if (var->error_doc != 1)
			ft_builtins(last_list, env_list, var);
		ft_close_fd(var);
		return ;
	}
	last_child = ft_fork(var, &list, &list_heredoce_tmp, env_list);
	ft_wait(var, last_child, &list_heredoce);
}

void	ft_child_proccess(t_list *last_list, t_env **env_list,
				t_var *var, t_list_str **list_heredoc)
{
	int		j;
	char	**cmd;

	ft_serche_for_doc(last_list, *env_list, var, list_heredoc);
	ft_serche_for_cmd(&last_list);
	if (last_list->type_d != WORD)
		exit (0);
	ft_duplicate(var);
	j = 0;
	while (j < (var->n_cmd - 1) * 2)
		close(var->fd[j++]);
	if (ft_builtins(last_list, env_list, var) == 1)
	{
		cmd = check_cmd(last_list, *env_list);
		if (!cmd)
			exit(127);
		if (execve(cmd[0], cmd, (*env_list)->env) == -1)
		{
			error_isdir(cmd);
			error_cmd(cmd);
		}
	}
	exit(g_state_exit);
}
