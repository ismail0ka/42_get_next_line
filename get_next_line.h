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
# include <stdint.h>

char	*get_next_line(int fd);
int		ft_read_line(int fd, char **buffer_p);
char	*ft_get_line(char **s);

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
# endif
#endif //GET_NEXT_LINE_H
