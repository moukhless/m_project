/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_append_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:21:37 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/28 00:24:15 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_open_append_file(t_list *node, t_var *var, t_env *env_list)
{
	t_list		*list;
	char		*str_doc;
	t_list_str	*list_str;
	int			outfile;

	list = NULL;
	list_str = NULL;
	outfile = -1;
	ft_init_var(var);
	ft_make_list(node->cmd[1], &list, var);
	str_doc = get_string_doc(list, var, env_list, &list_str);
	if (!str_doc)
		ft_msg_null_doc(node, var);
	if (var->error_doc != 1)
	{
		outfile = open(str_doc, O_RDWR | O_CREAT | O_APPEND, 0777);
		if (outfile == -1)
			ft_msg_error_outfile(str_doc, var);
	}
	ft_lstclear(&list);
	list_strclear(&list_str);
	return (outfile);
}
