/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_for_DOC.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 22:41:34 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/28 00:04:07 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_serche_for_doc(t_list *last_list, t_env *env_list,
				t_var *var, t_list_str **list_heredoc)
{
	int	other_inf;
	int	other_outf;

	other_inf = 0;
	other_outf = 0;
	while (last_list && last_list->type_d != PIPE_LINE)
	{
		if (last_list->type_d == HERE_DOC)
			serch_for_heredoc(var, list_heredoc, &other_inf);
		else if (last_list->type_d == REDIR_IN)
			serch_for_inf(last_list, var, env_list, &other_inf);
		else if (last_list->type_d == REDIR_OUT
			|| last_list->type_d == DREDIR_OUT)
			serch_for_outf(last_list, env_list, var, &other_outf);
		last_list = last_list->next;
	}
}

void	serch_for_outf(t_list *last_list, t_env *env_list,
				t_var *var, int *other_outf)
{
	int	file;

	if (last_list->type_d == REDIR_OUT)
		file = ft_open_outfile(last_list, var, env_list);
	else
		file = ft_open_append_file(last_list, var, env_list);
	if (file != -1)
	{
		if (*other_outf == 1)
		{
			close(var->std_out);
			*other_outf = 0;
		}
		*other_outf = 1;
		var->std_out = file;
	}
}

void	serch_for_inf(t_list *last_list, t_var *var,
				t_env *env_list, int *other_inf)
{
	int	file;

	file = ft_open_infile(last_list, var, env_list);
	if (file != -1)
	{
		if (ft_listchr(last_list, HERE_DOC) == 0)
			close(file);
		else
		{
			if (*other_inf == 1)
			{
				close(var->std_in);
				*other_inf = 0;
			}
			*other_inf = 1;
			var->std_in = file;
		}
	}
}

void	serch_for_heredoc(t_var *var, t_list_str **list_heredoc, int *other_inf)
{
	if (*other_inf == 1)
	{
		close(var->std_in);
		*other_inf = 0;
	}
	*other_inf = 1;
	var->std_in = (*list_heredoc)->fd;
	*list_heredoc = (*list_heredoc)->next;
}

int	ft_serche_for_redir_in(t_list *last_list)
{
	while (last_list && last_list->type_d != PIPE_LINE)
	{
		if (last_list->type_d == REDIR_IN)
			return (0);
		last_list = last_list->next;
	}
	return (1);
}
