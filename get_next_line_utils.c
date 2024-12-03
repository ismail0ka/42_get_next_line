/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:17:55 by ikarouat          #+#    #+#             */
/*   Updated: 2024/11/27 02:49:58 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp_b;

	if (!b)
		return (b);
	tmp_b = b;
	while (len > 0)
	{
		*(tmp_b++) = (unsigned char)c;
		len--;
	}
	return (b);
}

static void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)(s + s_len));
	i = 0;
	while (i < s_len)
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

static void	*ft_calloc(size_t count, size_t size)
{
	void	*heap_arr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	heap_arr = malloc(count * size);
	if (!heap_arr)
		return (NULL);
	ft_bzero(heap_arr, count * size);
	return (heap_arr);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

static char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*new_s;
	size_t	s_len;

	if (!s1)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s1);
	new_s = (char *)malloc(s_len + 1);
	if (!new_s)
		return (NULL);
	while (i < s_len)
	{
		new_s[i] = s1[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

static char	*ft_join_and_free(char *dst, char *src)
{
	char	*new_buff;
	int		i;
	int		len;
	char	*tmp;

	if (!dst)
		return (ft_strdup(src));
	if (!src)
		return (ft_strdup(dst));
	len = ft_strlen(dst) + ft_strlen(src);
	new_buff = malloc(len + 1);
	if (!new_buff)
		return (NULL);
	i = 0;
	tmp = (char *) dst;
	while (*(tmp) != '\0')
		new_buff[i++] = *(tmp++);
	tmp = (char *) src;
	while (*(tmp) != '\0')
		new_buff[i++] = *(tmp++);
	new_buff[i] = '\0';
	free(dst);
	return (new_buff);
}

int	ft_read_line(int fd, char **buffer_p)
{
	char	*buffer;
	ssize_t	bytes_count;

	while (1)
	{
		if (ft_strchr(*buffer_p, '\n'))
			break ;
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (-1);
		bytes_count = read(fd, buffer, BUFFER_SIZE);
		if (bytes_count < 0)
		{
			free(buffer);
			return (-1);
		}else if (bytes_count == 0)
		{
			free(buffer);
			return (0);
		}
		*buffer_p = ft_join_and_free(*buffer_p, buffer);
		free(buffer);
	}
	return (bytes_count);
}

char	*ft_get_remainder(char *s, size_t new_line_offset)
{
	size_t	i;
	char	*new_buf;

	i = 0;
	new_buf = ft_calloc(ft_strlen(s) - new_line_offset + 1, 1);
	while (s[new_line_offset + i])
	{
		new_buf[i] = s[new_line_offset + i];
		i++;
	}
	return (new_buf);
}

char	*ft_get_line(char **buffer_p)
{
	size_t	i;
	short	has_rem;
	char	*line;
	char	*s_remainder;

	i = 0;
	has_rem = 0;
	while ((*buffer_p)[i] != '\n'  && (*buffer_p)[i] != '\0')
		i++;

	if ((*buffer_p)[i] == '\n')
		has_rem = 1;
	i++;
	line = (char *)ft_calloc(i + 1, 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, *buffer_p, i + 1);
	if (has_rem)
		s_remainder = ft_get_remainder(*buffer_p, i);
	else
		s_remainder = 0;
	free(*buffer_p);
	*buffer_p = s_remainder;
	return (line);
}
