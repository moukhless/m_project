/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:55:16 by amoukhle          #+#    #+#             */
/*   Updated: 2023/04/12 17:23:24 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_strncmp(char *s1, char *s2, int n)
{
    int i;

    i = 0;
    while (s1[i] && i < n)
    {
        if (s1[i] != s2[i])
            return (1);
        i++;
    }
    return (0);
}

int	num_w(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (!str[i])
			break ;
		while (str[i] != c && str[i])
			i++;
		count++;
	}
	return (count);
}

char	*fill_str(char **st, char *s, int start, int end)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(end - start + 1);
	if (!str)
	{
		while (*st)
			free((*st)++);
		free(st);
		return (NULL);
	}
	while (start < end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	**ft_split(char *s, char c)
{
	char	**str;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	str = (char **)malloc((num_w((char *)s, c) + 1) * sizeof(char *));
	if (!str || !s)
		return (NULL);
	while (i < num_w((char *)s, c) + 1)
	{
		while (s[start] == c && s[start])
			start++;
		if (!s[start])
			break ;
		end = start;
		while (s[end] != c && s[end])
			end++;
		str[i++] = fill_str(str, (char *)s, start, end);
		start = end;
	}
	str[i] = NULL;
	return (str);
}