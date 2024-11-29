/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:45:50 by ikarouat          #+#    #+#             */
/*   Updated: 2024/11/27 02:50:01 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	int		read_status;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	read_status = ft_read_line(fd, &buffer);
	if (read_status == -1)
		return (NULL);
	line = ft_get_line(&buffer);
	return (line);
}
