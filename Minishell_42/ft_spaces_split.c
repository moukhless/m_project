/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaces_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 07:43:51 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/28 00:00:57 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	wc(char *s)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == ' ' || s[i] == '\t') && s[i])
			i++;
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
			counter++;
		while (s[i] != ' ' && s[i] != '\t' && s[i])
			i++;
	}
	return (counter);
}

static char	**check_isfree(char **str)
{
	while (*str)
		free (*str++);
	free (str);
	return (NULL);
}

static void	ft_skip(char const *s, size_t *start, size_t *end)
{
	while ((s[*start] == ' ' || s[*start] == '\t') && s[*start] != '\0')
		*start = *start + 1;
	*end = *start;
	while (s[*end] != ' ' && s[*end] != '\t' && s[*end] != '\0')
		*end = *end + 1;
}

char	**ft_spaces_split(char *s)
{
	char	**str_split;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s)
		return (0);
	str_split = (char **)malloc((wc((char *)s) + 1) * sizeof(char *));
	if (!str_split)
		return (0);
	start = 0;
	i = 0;
	while (i < wc((char *)s))
	{
		ft_skip(s, &start, &end);
		str_split[i++] = ft_substr((char *)s, start, end - start);
		if (!*str_split)
			return (check_isfree(str_split));
		start = end;
	}
	*(str_split + i) = NULL;
	return (str_split);
}
