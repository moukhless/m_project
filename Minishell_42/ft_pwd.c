/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:43:57 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/31 22:15:47 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_env *env_list, t_var *var)
{
	char	*str;
	t_env	*save;
	int		j;

	save = env_list;
	str = NULL;
	j = 0;
	while (save)
	{
		if (!ft_strcmp(save->key, "PWD"))
			str = save->val;
		save = save->next;
	}
	if (!str)
	{
		str = getcwd(NULL, 0);
		j = 1;
	}
	if (str)
	{
		write(var->std_out, str, ft_strlen(str));
		write(var->std_out, "\n", 1);
		if (j == 1)
			free(str);
	}
}
