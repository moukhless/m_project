/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:30:36 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/27 23:56:25 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handle_env_heredoc(t_list *list, t_var *var)
{
	if (list->next && list->type == ENV && list->state == GENERAL
		&& (list->next->type == QOUTE || list->next->type == DOUBLE_QUOTE)
		&& var->num_env % 2 != 0)
		return ("");
	return (list->content);
}

char	*get_string_heredoc(t_list *list, t_var *var, t_list_str **list_str)
{
	char	*tmp;

	while (list)
	{
		var->skip = 0;
		if (!skip_node_heredoc(list))
			ft_skip_node_heredoc(list, var);
		if (!var->skip && list->type == ENV)
		{
			var->num_env++;
			tmp = handle_env_heredoc(list, var);
			var->str = join_list_str(var->str, tmp, list_str);
		}
		else if (!var->skip)
		{
			var->num_env = 0;
			var->str = join_list_str(var->str, list->content, list_str);
		}
		list = list->next;
	}
	return (var->str);
}

void	ft_msg_error_heredoc(char *name)
{
	int	len_error;

	len_error = ft_strlen(strerror(errno));
	write(2, "bash: ", 6);
	write(2, name, ft_strlen(name));
	write(2, ": ", 2);
	write(2, strerror(errno), len_error);
	write (2, "\n", 1);
	exit(1);
}

char	*ft_name_file(void)
{
	static int	i;
	char		*name;
	char		*num;

	num = ft_itoa(i++);
	name = ft_strjoin("/tmp/here_doc", num);
	free(num);
	while (access(name, F_OK) != -1)
	{
		free(name);
		num = ft_itoa(i++);
		name = ft_strjoin("/tmp/here_doc", num);
		free(num);
	}
	return (name);
}

int	ft_open_heredoc(t_list *node, t_var *var)
{
	t_list		*list;
	char		*delimiter;
	t_list_str	*list_str;
	int			file;
	char		*name_file;

	list = NULL;
	list_str = NULL;
	name_file = ft_name_file();
	ft_init_var(var);
	ft_make_list(node->cmd[1], &list, var);
	delimiter = get_string_heredoc(list, var, &list_str);
	file = open(name_file, O_WRONLY | O_CREAT, 0777);
	if (file == -1)
		ft_msg_error_heredoc(name_file);
	fill_file(delimiter, file, var);
	file = open(name_file, O_RDONLY, 0777);
	if (file == -1)
		ft_msg_error_heredoc(name_file);
	ft_lstclear(&list);
	list_strclear(&list_str);
	ft_delete_here_doc(name_file);
	free(name_file);
	return (file);
}
