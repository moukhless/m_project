/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:50:44 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/28 00:24:30 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var	*init_vars(t_env *env_list)
{
	t_var	*tmp;

	tmp = (t_var *)malloc(sizeof(t_var));
	if (!tmp)
		return (0);
	tmp->end = 0;
	tmp->start = 0;
	tmp->flag1 = 0;
	tmp->flag2 = 0;
	tmp->num_env = 0;
	tmp->skip = 0;
	tmp->in_join = 0;
	tmp->q_dq = 0;
	tmp->env_list = env_list;
	return (tmp);
}

void	init_var(t_var *var, int num_pipe)
{
	var->n_cmd = num_pipe + 1;
	var->num_cmd = 0;
	var->std_in = 0;
	var->std_out = 1;
	var->error_doc = 0;
}

void	ft_duplicate(t_var *var)
{
	if (var->num_cmd == 0)
	{
		if (var->std_in != 0)
			dup2(var->std_in, STDIN_FILENO);
		if (var->n_cmd != 1)
			dup2(var->fd[1], STDOUT_FILENO);
		if (var->std_out != 1)
			dup2(var->std_out, STDOUT_FILENO);
	}
	else
	{
		dup2(var->fd[(var->num_cmd - 1) * 2], STDIN_FILENO);
		if (var->num_cmd != var->n_cmd - 1)
			dup2(var->fd[(var->num_cmd - 1) * 2 + 3], STDOUT_FILENO);
		if (var->std_out != 1)
			dup2(var->std_out, STDOUT_FILENO);
		if (var->std_in != 0)
			dup2(var->std_in, STDIN_FILENO);
	}
	if (var->std_in != 0)
		close(var->std_in);
	if (var->std_out != 1)
		close(var->std_out);
}

void	ft_init_var_delimiter(t_var *var)
{
	var->start = 0;
	var->end = 0;
	var->flag1 = 0;
	var->flag2 = 0;
	var->num_env = 0;
	var->str = NULL;
}
