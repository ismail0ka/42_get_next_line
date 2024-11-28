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
	iline_t		line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buffer)
		read_status = ft_read_file(fd, &buffer);
	if (read_status == -1)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_to_next_line(buffer, line.next_line_index);
	return (line.line);
}
