/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:53:10 by amoukhle          #+#    #+#             */
/*   Updated: 2022/12/21 21:25:12 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	size_tot;
	char	*p;
	size_t	counter;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	counter = 0;
	size_tot = count * size;
	p = malloc(size_tot);
	if (!p)
		return (NULL);
	while (counter < size_tot)
	{
		p[counter] = '\0';
		counter++;
	}
	return (p);
}

int	check_break_line(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		str = (char *)ft_calloc(ft_strlen(s2) + 1, 1);
	else
		str = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	if (!str)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[j])
			str[i++] = s1[j++];
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	free(s1);
	return (str);
}

char	*str_until_break_line(char *s2)
{
	int		i;
	char	*str;

	i = 0;
	while (s2[i] != '\n' && s2[i])
		i++;
	if (s2[i] == '\n')
		i++;
	str = ft_calloc(i + 1, 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s2[i] != '\n' && s2[i])
	{
		str[i] = s2[i];
		i++;
	}
	if (s2[i] == '\n')
		str[i] = s2[i];
	return (str);
}

char	*ft_delete_until_break_line(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	s = ft_calloc(ft_strlen(str) - i + 1, 1);
	if (!s)
		return (NULL);
	j = 0;
	while (str[i])
		s[j++] = str[++i];
	free(str);
	return (s);
}
