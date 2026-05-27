/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:38:03 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/27 22:10:01 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./parse_map_private.h"
#include "../parse_file_private.h"

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
static bool	compute_map_size(t_list *line_list, t_map *map)
{
	size_t	cur_x_size;
	size_t	cur_y_size;

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
		if (cur_x_size > (size_t)map->x_size)
			map->x_size = (int)cur_x_size;
		line_list = line_list->next;
	}
	map->y_size = (int)cur_y_size;
	if (map->y_size == 0)
	{
		print_error(ERROR_MAP_EMPTY);
		return (false);
	}
	return (true);
}

static bool	alloc_map(t_map *map)
{
	int	y;

	map->data = malloc(sizeof(char *) * map->y_size);
	if (map == NULL)
	{
		print_error(strerror(errno));
		return (false);
	}
	y = 0;
	while (y < map->y_size)
	{
		map->data[y] = malloc(sizeof(char) * map->x_size);
		if (map->data[y] == NULL)
		{
			while (y-- > 0)
				free(map->data[y]);
			free(map->data);
			print_error(strerror(errno));
			return (false);
		}
		++y;
	}
	return (true);
}

// left-hand coordinate system
static void	convert_list_to_array(t_list *line_list, t_map *map)
{
	char			*content;
	int				x;
	int				y;

	y = map->y_size - 1;
	while (y >= 0)
	{
		content = ft_lst_pop_front(&line_list);
		x = 0;
		while (content[x] != '\0')
		{
			map->data[y][x] = content[x];
			++x;
		}
		while (x < map->x_size)
		{
			map->data[y][x] = ' ';
			++x;
		}
		free(content);
		--y;
	}
}

bool	read_map(int fd, t_map *map)
{
	t_list	*line_list;

	line_list = NULL;
	if (!read_map_as_list(fd, &line_list) \
	|| !compute_map_size(line_list, map) \
	|| !alloc_map(map))
	{
		ft_lstclear(&line_list, free);
		return (false);
	}
	convert_list_to_array(line_list, map);
	return (true);
}
