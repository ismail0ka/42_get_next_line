/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:43:36 by ikarouat          #+#    #+#             */
/*   Updated: 2024/11/09 21:01:11 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		read_file(int fd, char **buffer_p);
char	*get_line(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
void	*ft_calloc(size_t count, size_t size);

#endif
