/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 00:47:51 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/16 20:34:38 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"

char		*read_next_line(int fd, t_buf *buf);
static bool	init_next_line(t_next_line *next_line);
static bool	read_file(int fd, t_buf *buf);
static bool	append_to_next_line(t_next_line *next_line, char c);

char	*get_next_line(int fd)
{
	static t_buf	buf;
	char			*next_line;

	next_line = read_next_line(fd, &buf);
	if (next_line == NULL)
		ft_bzero(&buf, sizeof(t_buf));
	return (next_line);
}

char	*read_next_line(int fd, t_buf *buf)
{
	t_next_line		next_line;

	if (!init_next_line(&next_line))
		return (NULL);
	while (true)
	{
		if (!read_file(fd, buf) \
			|| (buf->read_bytes == 0 && next_line.len == 0))
		{
			free(next_line.data);
			return (NULL);
		}
		if (buf->read_bytes == 0)
			return (next_line.data);
		if (!append_to_next_line(&next_line, buf->data[buf->used_bytes++]))
		{
			free(next_line.data);
			return (NULL);
		}
		if (buf->data[buf->used_bytes - 1] == '\n' \
			|| buf->data[buf->used_bytes - 1] == '\0')
		{
			return (next_line.data);
		}
	}
}

static bool	init_next_line(t_next_line *next_line)
{
	next_line->data = ft_strdup("");
	if (next_line->data == NULL)
		return (false);
	next_line->allocated_size = 1;
	next_line->len = 0;
	return (true);
}

static bool	read_file(int fd, t_buf *buf)
{
	ssize_t	res;

	if (buf->used_bytes == buf->read_bytes)
	{
		res = read(fd, buf->data, BUFFER_SIZE);
		if (res < 0)
			return (false);
		buf->read_bytes = res;
		buf->used_bytes = 0;
	}
	return (true);
}

static bool	append_to_next_line(t_next_line *next_line, char c)
{
	char	*new_ptr;

	if (c == '\0')
		return (true);
	if (next_line->len + 1 == next_line->allocated_size)
	{
		if (next_line->allocated_size < 1024)
			next_line->allocated_size = next_line->allocated_size * 2;
		else
			next_line->allocated_size = next_line->allocated_size + 1024;
		new_ptr = (char *)malloc(sizeof(char) * next_line->allocated_size);
		if (new_ptr == NULL)
			return (false);
		ft_memcpy(new_ptr, next_line->data, next_line->len);
		new_ptr[next_line->len++] = c;
		new_ptr[next_line->len] = '\0';
		free(next_line->data);
		next_line->data = new_ptr;
	}
	else
	{
		next_line->data[next_line->len++] = c;
		next_line->data[next_line->len] = '\0';
	}
	return (true);
}
