/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:45:50 by ikarouat          #+#    #+#             */
/*   Updated: 2024/11/09 00:36:20 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			read_status;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buffer)
		read_status = read_file(fd, &buffer);//get all lines
	if (read_status == -1)
		return (NULL);
	line = get_line(buffer);//render a line
	while (buffer)
		to_next_line(&buffer);//set buffer to next line
	return (line);
}
/*int main()
{
	int fd = open("test.txt", O_RDWR);
	//char *buf;
	//while ((buf = ) != NULL)
	printf("%s\n", get_next_line(fd));
	return 0;
}*/
//GET AND RETURN EVERYLINE
