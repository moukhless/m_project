/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:06:25 by hachahbo          #+#    #+#             */
/*   Updated: 2023/07/29 10:07:56 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*find_small(t_env *list)
{
	t_env	*min;

	min = list;
	while (list->next)
	{
		if (ft_strcmp(min->content, list->next->content) > 0)
			min = list->next;
		list = list->next;
	}
	return (min);
}

void	remove_node(t_env **head, char *min)
{
	t_env	*current;
	t_env	*previous;

	previous = NULL;
	current = *head;
	while (current != NULL)
	{
		if (!ft_strcmp(current->content, min))
		{
			if (previous == NULL)
				*head = current->next;
			else
				previous->next = current->next;
			free(current);
			return ;
		}
		previous = current;
		current = current->next;
	}
}

char	*until_equal_or_plus(char *big_str, char c)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (!ft_strchr(big_str, '='))
		return (ft_strdup(big_str));
	while (big_str[i] != c && big_str[i])
		i++;
	str = malloc(sizeof(char) * i + 1);
	i = 0;
	j = 0;
	while (big_str[i] != c && big_str[j])
	{
		if (big_str[j] == '\\')
			j++;
		str[i] = big_str[j];
		i++;
		j++;
	}
	if (ft_strchr(big_str, '\\'))
		i--;
	str[i] = '\0';
	return (str);
}

int	check_double_key(t_env *new_list, t_env *new_env)
{
	while (new_list)
	{
		if (!ft_strcmp(new_list->key, new_env->key))
			return (1);
		new_list = new_list->next;
	}
	return (0);
}

void	insert(t_env **root, t_env *item)
{
	t_env	*temp;
	t_env	*ptr;

	temp = malloc(sizeof(t_env));
	temp -> val = item -> val;
	temp -> key = item -> key;
	temp -> content = item -> content;
	temp -> next = NULL;
	if (*root == NULL)
		*root = temp;
	else
	{
		ptr = *root;
		while (ptr-> next != NULL)
			ptr = ptr->next;
		ptr -> next = temp;
	}
}
