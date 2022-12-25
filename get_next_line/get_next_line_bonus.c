/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:38:22 by amoukhle          #+#    #+#             */
/*   Updated: 2022/12/23 23:10:13 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*buff;
	char		*line;
	int			bytes;

	if (fd < 0)
		return (NULL);
	bytes = 1;
	buff = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	while (bytes > 0 && check_break_line(str[fd]) == 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1 || BUFFER_SIZE == 0
			|| (buff[0] == 0 && (!str[fd] || str[fd][0] == 0)))
			return (free(str[fd]), free(buff), str[fd] = NULL);
		if (bytes < BUFFER_SIZE)
			buff[bytes] = '\0';
		str[fd] = ft_strjoin(str[fd], buff);
	}
	free(buff);
	line = str_until_break_line(str[fd]);
	str[fd] = ft_delete_until_break_line(str[fd]);
	return (line);
}
