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

static void    *ft_memset(void *b, int c, size_t len)
{
        unsigned char   *tmp_b;

        if (!b)
                return (b);
        tmp_b = b;
        while (len > 0)
        {
                *(tmp_b++) = (unsigned char) c;
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
		*buffer_p = ft_join_and_free(*buffer_p, buffer);
		free(buffer);
	}
}

iline_t	ft_get_line(char *s)
{
	size_t	i;
	iline_t line;

	i = 0;
	while (s[i] != '\n')
		i++;
	line.next_line_index = ++i;
	line.line = (char *)malloc(i + 1);
	if (!(line.line))
		line.line = NULL;
	ft_strlcpy(line.line, s, i + 1);
	return (line);
}

char	*ft_to_next_line(char *buffer, unsigned int next_index)
{
	char	*new_buf;
	size_t	new_len;
	size_t	i;

	i = 0;
	new_len = ft_strlen(buffer) - next_index;
	new_buf = ft_calloc(new_len + 1, sizeof(char));
	if (!new_buf)
		return (NULL);
	while (buffer[next_index + i])
	{
		new_buf[i] = buffer[next_index + i];
		i++;
	}
	free(buffer);
	return new_buf;
}
