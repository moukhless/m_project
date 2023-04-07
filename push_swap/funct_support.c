/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:19:30 by amoukhle          #+#    #+#             */
/*   Updated: 2023/04/06 22:08:03 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	int		ch;
	int		signe;
	long	res;

	ch = 0;
	signe = 1;
	res = 0;
	while (str[ch] >= 9 && str[ch] <= 13 && str[ch] == ' ')
		ch++;
	if (str[ch] == '-' || str[ch] == '+')
		if (str[ch++] == '-')
			signe = -1;
	while (str[ch] >= '0' && str[ch] <= '9')
	{
		if (res * signe > INT_MAX || res * signe < INT_MIN)
			return (res * signe);
		res = (res * 10) + (str[ch] - '0');
		ch++;
	}
	return (res * signe);
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
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(end - start + 1);
	if (!str)
	{
		while (st[j])
			free(st[j++]);
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
	str = (char **)malloc((num_w(s, c) + 1) * sizeof(char *));
	if (!str || !s)
		return (NULL);
	while (i < num_w(s, c) + 1)
	{
		while (s[start] == c && s[start])
			start++;
		if (!s[start])
			break ;
		end = start;
		while (s[end] != c && s[end])
			end++;
		str[i++] = fill_str(str, s, start, end);
		start = end;
	}
	str[i] = NULL;
	return (str);
}
