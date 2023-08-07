/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:10:40 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/27 23:11:32 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_to_history(char *input)
{
	if (ft_strlen(input) > 0)
		add_history(input);
	free(input);
}

void	ft_free_head_vars(t_var *vars, t_list **head)
{
	ft_lstclear(head);
	free(vars);
}

int	check_the_plus(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' && str[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*delete_back_slash(char *str)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	while (str[i])
		i++;
	s = (char *)malloc(i + 1);
	j = 0;
	i = 0;
	while (str[j])
	{
		if (str[j] == '\\')
			j++;
		s[i] = str[j];
		i++;
		j++;
	}
	s[i] = '\0';
	return (s);
}
