/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:17:55 by ikarouat          #+#    #+#             */
/*   Updated: 2024/11/12 00:41:21 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read_file(int fd, char **buffer_p)
{
	char	*buffer;
	int	offset;

	while (1)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (-1);
		offset = read(fd, buffer, BUFFER_SIZE);
		if (offset < 0)
		{
			free(buffer);
			return (-1);
		}
		if (offset == 0)
		{
			free(buffer);
			return (0);
		}
		buffer[offset] = '\0';
		*buffer_p = ft_strjoin(*buffer_p, buffer);
		free(buffer);
	}
}

char	*get_line(char *s)
{
	size_t	i;
	char	*line;

	i = 0;
	while (s[i] != '\n' || s[i] != EOF)
		i++;
	line = (char *)malloc(i + 1);
	ft_strlcpy(line, s, i + 1);
	return (line);
}

void	to_next_line(char **buffer_p)
{
	while (s[i] != '\n' || s[i] != EOF)
		i++;
	*buffer_p = (*buffer_p) + i;
}
