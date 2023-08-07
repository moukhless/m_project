/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:50:41 by hachahbo          #+#    #+#             */
/*   Updated: 2023/07/28 18:28:08 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	list_stradd_back(t_list_str **lst, t_list_str *new)
{
	t_list_str	*tmp;
	int			i;

	i = 0;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = list_strlast(*lst);
	tmp->next = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
	new->prev = tmp;
}
