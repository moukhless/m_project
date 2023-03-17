/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:24:18 by amoukhle          #+#    #+#             */
/*   Updated: 2023/03/07 22:22:30 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_enemy	*new_enemy(int x_enemy, int y_enemy)
{
	t_enemy	*n_enemy;

	n_enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (!n_enemy)
		return (NULL);
	n_enemy->x_enemy = x_enemy;
	n_enemy->y_enemy = y_enemy;
	n_enemy->next = NULL;
	return (n_enemy);
}

void	addenemy(t_enemy **s_enemy, t_enemy *n_enemy)
{
	t_enemy	*p;

	if (!*s_enemy)
	{
		*s_enemy = n_enemy;
		return ;
	}
	p = *s_enemy;
	*s_enemy = n_enemy;
	n_enemy->next = p;
}

void	t_enemy_clean(t_enemy **s_enemy)
{
	t_enemy	*p;

	p = *s_enemy;
	while (*s_enemy)
	{
		p = (*s_enemy)->next;
		free(*s_enemy);
		*s_enemy = p;
	}
}
