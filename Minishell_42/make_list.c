/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 06:09:13 by hachahbo          #+#    #+#             */
/*   Updated: 2023/07/27 23:27:02 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sit_type(t_list *node)
{
	if ((node->content[0] >= 'A' && node->content[0] <= 'Z')
		|| (node->content[0] >= 'a' && node->content[0] <= 'z')
		|| node->content[0] == '_')
		return ;
	if (node->type == WORD)
		node->type = SPECIAL_CHAR;
}

void	ft_make_list(char *input, t_list **head, t_var *vars)
{
	t_list	*new;
	char	*str;

	while (1)
	{
		input = skip_spaces(input);
		str = check_data(input, &vars->start, &vars->end);
		if (str == NULL)
		{
			free(str);
			break ;
		}
		new = ft_lstnew(str, NULL);
		ft_sit_type(new);
		ft_status(new, &vars->flag1, &vars->flag2);
		ft_lstadd_back(head, new);
		free(str);
	}
}

void	ft_make_new_list_w_s(t_list *new_list, t_list **new_list_w_s)
{
	t_list	*new;

	while (new_list)
	{
		if (new_list->type == WHITE_SPACE && new_list->state == GENERAL)
		{
			new_list = new_list->next;
			continue ;
		}
		new = ft_lstnew(new_list->content, NULL);
		new->state = new_list->state;
		ft_lstadd_back(new_list_w_s, new);
		new_list = new_list->next;
	}
}

int	count_arg(t_list *new_list_w_s)
{
	int	count;

	count = 0;
	while (new_list_w_s
		&& (new_list_w_s->type != PIPE_LINE
			|| new_list_w_s->state == IN_DQUOTE))
	{
		if ((new_list_w_s->type == REDIR_IN || new_list_w_s->type == REDIR_OUT
				|| new_list_w_s->type == HERE_DOC
				|| new_list_w_s->type == DREDIR_OUT)
			&& new_list_w_s->state == GENERAL)
		{
			new_list_w_s = new_list_w_s->next->next;
			continue ;
		}
		count++;
		new_list_w_s = new_list_w_s->next;
	}
	return (count);
}

void	get_command_and_arg(char **cmd, t_list *new_list_w_s)
{
	int	i;

	i = 0;
	while (new_list_w_s
		&& (new_list_w_s->type != PIPE_LINE
			|| new_list_w_s->state == IN_DQUOTE))
	{
		if (!is_doc(new_list_w_s))
		{
			new_list_w_s = new_list_w_s->next->next;
			continue ;
		}
		cmd[i++] = ft_strdup(new_list_w_s->content);
		new_list_w_s = new_list_w_s->next;
	}
	cmd[i] = NULL;
}
