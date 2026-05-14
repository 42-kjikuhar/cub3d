/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 00:47:51 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/13 01:39:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"

static bool	read_file(int fd, t_buf *buf);
static void	append_to_next_line(t_next_line *next_line, char c);

char	*get_next_line(int fd)
{
	static t_buf	buf;
	t_next_line		next_line;

	next_line.data = ft_strdup("");
	next_line.allocated_size = 1;
	next_line.len = 0;
	while (true)
	{
		if (next_line.data == NULL || !read_file(fd, &buf) \
			|| (buf.read_bytes == 0 && next_line.len == 0))
		{
			free(next_line.data);
			ft_bzero(&buf, sizeof(t_buf));
			return (NULL);
		}
		if (buf.read_bytes == 0)
			break ;
		if (buf.data[buf.used_bytes] == '\n' || buf.data[buf.used_bytes] == '\0')
		{
			++buf.used_bytes;
			break ;
		}
		append_to_next_line(&next_line, buf.data[buf.used_bytes++]);
	}
	return (next_line.data);
}

static bool	read_file(int fd, t_buf *buf)
{
	ssize_t	res;

	if (buf->used_bytes == buf->read_bytes)
	{
		res = read(fd, buf->data, BUFFER_SIZE);
		if (res < 0 || res == 0)
			return (false);
		buf->read_bytes = res;
		buf->used_bytes = 0;
	}
	return (true);
}

static void	append_to_next_line(t_next_line *next_line, char c)
{
	char	*new_ptr;

	if (next_line->len + 1 == next_line->allocated_size)
	{
		if (next_line->allocated_size < 1024)
			next_line->allocated_size = next_line->allocated_size * 2;
		else
			next_line->allocated_size = next_line->allocated_size + 1024;
		new_ptr = (char *)malloc(sizeof(char) * next_line->allocated_size);
		if (new_ptr != NULL)
		{
			ft_memcpy(new_ptr, next_line->data, next_line->len);
			new_ptr[next_line->len++] = c;
			new_ptr[next_line->len] = '\0';
		}
		free(next_line->data);
		next_line->data = new_ptr;
	}
	else
	{
		next_line->data[next_line->len++] = c;
		next_line->data[next_line->len] = '\0';
	}
}
