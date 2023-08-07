/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:25:26 by hachahbo          #+#    #+#             */
/*   Updated: 2023/07/29 10:13:19 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../minishell.h"

int	ft_lexer(t_list *node)
{
	if (ft_strcmp(node->content, " ") == 0)
		node->type = WHITE_SPACE;
	else if (ft_strcmp(node->content, "\'") == 0)
		node->type = QOUTE;
	else if (ft_strcmp(node->content, "\"") == 0)
		node->type = DOUBLE_QUOTE;
	else if (ft_strcmp(node->content, "$") == 0)
		node->type = ENV;
	else if (ft_strcmp(node->content, "?") == 0)
		node->type = Q_MARK;
	else if (ft_strcmp(node->content, "|") == 0)
		node->type = PIPE_LINE;
	else if (ft_strcmp(node->content, "<") == 0)
		node->type = REDIR_IN;
	else if (ft_strcmp(node->content, ">") == 0)
		node->type = REDIR_OUT;
	else if (ft_strcmp(node->content, "<<") == 0)
		node->type = HERE_DOC;
	else if (ft_strcmp(node->content, ">>") == 0)
		node->type = DREDIR_OUT;
	else
		node->type = WORD; 
	return (0);
}

t_list_str	*new_list_str(char *content, int fd)
{
	t_list_str	*tmp;

	tmp = (t_list_str *)malloc(sizeof(t_list_str));
	if (!tmp)
		return (0);
	tmp->content = content;
	tmp->fd = fd;
	tmp->next = 0;
	return (tmp);
}

char	**ft_str_double_dup(char **str)
{
	int		count;
	int		i;
	char	**strdup;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		count++;
		i++;
	}
	strdup = (char **)malloc(sizeof(char *) * (count + 1));
	if (!strdup)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		strdup[i] = ft_strdup(str[i]);
		i++;
	}
	strdup[i] = NULL;
	return (strdup);
}

void	sit_type(t_list *list)
{
	if (list->cmd[0])
	{
		if (ft_strcmp(list->cmd[0], "<") == 0)
			list->type_d = REDIR_IN;
		else if (ft_strcmp(list->cmd[0], ">") == 0)
			list->type_d = REDIR_OUT;
		else if (ft_strcmp(list->cmd[0], "<<") == 0)
			list->type_d = HERE_DOC;
		else if (ft_strcmp(list->cmd[0], ">>") == 0)
			list->type_d = DREDIR_OUT;
		else if (ft_strcmp(list->cmd[0], "|") == 0)
			list->type_d = PIPE_LINE;
		else
			list->type_d = WORD;
	}
}

t_list	*ft_lstnew(void *content, char **cmd)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (0);
	tmp->content = ft_strdup(content);
	tmp->cmd = ft_str_double_dup(cmd);
	ft_lexer(tmp);
	sit_type(tmp);
	tmp->next = 0;
	tmp->prev = 0;
	return (tmp);
}
