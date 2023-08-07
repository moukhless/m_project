/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:50:08 by hachahbo          #+#    #+#             */
/*   Updated: 2023/07/28 18:27:51 by hachahbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_str	*list_strlast(t_list_str *lst)
{
	t_list_str	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next != 0)
		tmp = tmp->next;
	return (tmp);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next != 0)
		tmp = tmp->next;
	return (tmp);
}
