/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_outfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:38:47 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/28 00:24:07 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_msg_error_outfile(char *str_DOC, t_var *var)
{
	int	len_error;

	len_error = ft_strlen(strerror(errno));
	write(2, "bash: ", 6);
	write(2, str_DOC, ft_strlen(str_DOC));
	write (2, ": ", 2);
	write(2, strerror(errno), len_error);
	write (2, "\n", 1);
	var->error_doc = 1;
	if (var->n_cmd != 1 || var->is_built != 1)
		exit(1);
}

int	ft_open_outfile(t_list *node, t_var *var, t_env *env_list)
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
		outfile = open(str_doc, O_RDWR | O_CREAT | O_TRUNC, 0777);
		if (outfile == -1)
			ft_msg_error_outfile(str_doc, var);
	}
	ft_lstclear(&list);
	list_strclear(&list_str);
	return (outfile);
}
