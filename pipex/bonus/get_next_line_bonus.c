/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:20:51 by amoukhle          #+#    #+#             */
/*   Updated: 2023/05/08 15:26:04 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buff;
	char		*line;
	int			bytes;

	bytes = 1;
	buff = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	while (bytes > 0 && check_break_line(str) == 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1 || fd < 0 || BUFFER_SIZE == 0
			|| (buff[0] == 0 && (!str || str[0] == 0)))
			return (free(str), free(buff), str = NULL);
		if (bytes < BUFFER_SIZE)
			buff[bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	line = str_until_break_line(str);
	str = ft_delete_until_break_line(str);
	return (line);
}
