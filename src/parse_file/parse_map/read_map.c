/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:38:03 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/29 00:05:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./parse_map_private.h"
#include "../parse_file_private.h"

static bool	read_map_as_list(int fd, t_list **line_list);
static bool	compute_map_size(t_list *line_list, int *x_size, int *y_size);
static void	set_map_from_list(t_list *line_list);

bool	read_map(int fd)
{
	t_list	*line_list;
	int		x_size;
	int		y_size;

	line_list = NULL;
	if (!read_map_as_list(fd, &line_list) \
		|| !compute_map_size(line_list, &x_size, &y_size) \
		|| !allocate_map(x_size, y_size))
	{
		ft_lstclear(&line_list, free);
		return (false);
	}
	set_map_from_list(line_list);
	return (true);
}

static bool	read_map_as_list(int fd, t_list **line_list)
{
	char	*line;

	while (true)
	{
		if (!read_next_line(fd, &line))
			return (false);
		if (line == NULL)
			return (true);
		if (*line_list == NULL && is_blank_line(line))
			free(line);
		else if (*line_list != NULL && is_blank_line(line))
		{
			free(line);
			print_error(ERROR_MAP_EMPTY_LINE);
			return (false);
		}
		else if (!ft_lst_push_back(line_list, line))
		{
			free(line);
			print_error(strerror(errno));
			return (false);
		}
	}
}

/* 無駄な終端スペースを省ける余地がある。 */
static bool	compute_map_size(t_list *line_list, int *x_size, int *y_size)
{
	size_t	cur_x_size;
	size_t	cur_y_size;

	*x_size = 0;
	cur_y_size = 0;
	while (line_list != NULL)
	{
		cur_x_size = ft_strlen(line_list->content);
		++cur_y_size;
		if (cur_x_size > INT_MAX || cur_y_size > INT_MAX)
		{
			print_error(ERROR_MAP_TOO_LARGE);
			return (false);
		}
		if (cur_x_size > (size_t)(*x_size))
			*x_size = (int)cur_x_size;
		line_list = line_list->next;
	}
	*y_size = (int)cur_y_size;
	if (*y_size == 0)
	{
		print_error(ERROR_MAP_EMPTY);
		return (false);
	}
	return (true);
}

// left hand coordinate system
static void	set_map_from_list(t_list *line_list)
{
	char	*content;
	int		x;
	int		y;

	y = map_size(Y_AXIS) - 1;
	while (y >= 0)
	{
		content = ft_lst_pop_front(&line_list);
		x = 0;
		while (content[x] != '\0')
		{
			set_map(content[x], x, y);
			++x;
		}
		while (x < map_size(X_AXIS))
		{
			set_map(' ', x, y);
			++x;
		}
		free(content);
		--y;
	}
}
