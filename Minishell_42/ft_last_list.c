/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:08:38 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/27 23:25:31 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_finale_list(t_list *new_list_w_s, t_list **last_list)
{
	int		is_cmd;
	int		is_doc;

	is_cmd = 0;
	is_doc = 0;
	while (new_list_w_s)
	{
		if ((new_list_w_s->type == WORD || new_list_w_s->type == ENV
				|| new_list_w_s->state == IN_DQUOTE) && is_cmd == 1)
		{
			new_list_w_s = new_list_w_s->next;
			continue ;
		}
		ft_split_list(&new_list_w_s, last_list, &is_cmd, &is_doc);
		if (new_list_w_s && is_doc == 0)
			new_list_w_s = new_list_w_s->next;
		is_doc = 0;
	}
}

void	ft_split_list(t_list **new_list_w_s,
				t_list **last_list, int *is_cmd, int *is_doc)
{
	if (((*new_list_w_s)->type == WORD || (*new_list_w_s)->type == ENV
			|| (*new_list_w_s)->state == IN_DQUOTE) && *is_cmd == 0)
	{
		get_command((*new_list_w_s), last_list);
		*is_cmd = 1;
	}
	else if (((*new_list_w_s)->type == REDIR_IN
			|| (*new_list_w_s)->type == REDIR_OUT
			|| (*new_list_w_s)->type == HERE_DOC
			|| (*new_list_w_s)->type == DREDIR_OUT)
		&& (*new_list_w_s)->state == GENERAL)
	{
		get_doc(new_list_w_s, last_list);
		*is_doc = 1;
	}
	else if ((*new_list_w_s)->type == PIPE_LINE
		&& (*new_list_w_s)->state == GENERAL)
	{
		get_pipe((*new_list_w_s), last_list);
		*is_cmd = 0;
	}
}

void	get_command(t_list *new_list_w_s, t_list **last_list)
{
	int		num_arg;
	char	**cmd;
	int		save_state;
	t_list	*new;

	save_state = new_list_w_s->state;
	num_arg = count_arg(new_list_w_s);
	cmd = (char **)malloc(sizeof(char *) * (num_arg + 1));
	if (!cmd)
		affiche_error();
	get_command_and_arg(cmd, new_list_w_s);
	new = ft_lstnew(NULL, cmd);
	if (save_state == 0)
		new->type_d = WORD;
	ft_lstadd_back(last_list, new);
	free_double(cmd);
}

void	get_doc(t_list **new_list_w_s, t_list **last_list)
{
	char	**cmd;
	int		i;
	t_list	*new;

	cmd = (char **)malloc(sizeof(char *) * (3));
	if (!cmd)
		affiche_error();
	i = 0;
	while (i < 2 && *new_list_w_s)
	{
		cmd[i++] = ft_strdup((*new_list_w_s)->content);
		*new_list_w_s = (*new_list_w_s)->next;
	}
	cmd[i] = NULL;
	new = ft_lstnew(NULL, cmd);
	ft_lstadd_back(last_list, new);
	free_double(cmd);
}

void	get_pipe(t_list *new_list_w_s, t_list **last_list)
{
	char	**cmd;
	t_list	*new;

	cmd = (char **)malloc(sizeof(char *) * (2));
	if (!cmd)
		affiche_error();
	cmd[0] = ft_strdup(new_list_w_s->content);
	cmd[1] = NULL;
	new = ft_lstnew(NULL, cmd);
	ft_lstadd_back(last_list, new);
	free_double(cmd);
}
