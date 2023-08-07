/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:27:30 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/28 00:19:10 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_line_in_fd(char *line, int fd)
{
	char	*line_with_n;

	line_with_n = ft_strjoin(line, "\n");
	write(fd, line_with_n, ft_strlen(line_with_n));
	free(line_with_n);
}

void	fill_file(char *delimiter, int fd, t_var *var)
{
	char		*line;
	t_list_str	*list_str;

	list_str = NULL;
	while (1)
	{
		get_value(3);
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		if (var->q_dq == 0)
			ft_expand_in_heredoc(var, line, &list_str, fd);
		else
			print_line_in_fd(line, fd);
		free(line);
		list_strclear(&list_str);
	}
	close (fd);
}

void	ft_expand_in_heredoc(t_var *var, char *line,
				t_list_str **list_str, int fd)
{
	t_list	*list;
	char	*str;
	char	*str_with_n;

	list = NULL;
	ft_init_var_delimiter(var);
	ft_make_list(line, &list, var);
	str = get_string_delimiter(list, var, var->env_list, list_str);
	ft_lstclear(&list);
	if (!str)
		str = "";
	str_with_n = ft_strjoin(str, "\n");
	write(fd, str_with_n, ft_strlen(str_with_n));
	free(str_with_n);
}

char	*get_string_delimiter(t_list *list, t_var *var,
				t_env *env_list, t_list_str **list_str)
{
	char	*tmp;

	while (list)
	{
		var->skip = 0;
		if (!skip_node_delimiter(list, var))
			ft_skip_node_delimiter(var);
		if (!var->skip && list->type == ENV)
		{
			var->num_env++;
			tmp = handle_env_in_heredoc(list, env_list, var->num_env);
			if (!tmp)
				tmp = "";
			var->str = join_list_str(var->str, tmp, list_str);
		}
		else if (!var->skip)
			var->str = join_list_str(var->str, list->content, list_str);
		list = list->next;
	}
	return (var->str);
}

char	*handle_env_in_heredoc(t_list *list, t_env *env_list, int num_env)
{
	if ((list->type == ENV && list->state == GENERAL
			&& (list->next == NULL || list->next->type == WHITE_SPACE)))
		return (list->content);
	else if (list->type == ENV)
	{
		if (list->next->type == WORD && num_env % 2 != 0)
			return (ft_expand_value(list->next->content, env_list));
		else if (list->next->type == Q_MARK && num_env % 2 != 0)
			return (ft_itoa(g_state_exit));
	}
	return (list->content);
}
