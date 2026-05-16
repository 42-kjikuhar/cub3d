/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:38:03 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/16 21:07:26 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./parse_file_private.h"

static bool	read_map_as_list(int fd, t_list **line_list)
{
	char	*line;

	while (true)
	{
		line = get_next_line(fd);
		if (errno != 0)
		{
			print_error(strerror(errno));
			return (false);
		}
		if (line == NULL)
			return (true);
		replace_char(line, '\n', '\0');
		if (line_list == NULL && is_blank_line(line))
			free(line);
		else if (line_list != NULL && !is_blank_line(line))
		{
			free(line);
			print_error("map has blank line, it is invalid");
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

static bool	compute_map_size(t_list const **line_list, t_map *map)
{
	t_list	*current;
	size_t	cur_x_size;

	current = *line_list;
	while (current != NULL)
	{
		cur_x_size = ft_strlen((*line_list)->content);
		if (cur_x_size > UINT_MAX)
		{
			print_error("x_size is over UINT_MAX");
			return (false);
		}
		if (cur_x_size > map->x_size)
			map->x_size = cur_x_size;
		if (map->y_size == UINT_MAX)
		{
			print_error("y_size is over UINT_MAX");
			return (false);
		}
		++map->y_size;
		current = current->next;
	}
}

static bool	alloc_map(t_map *map)
{
	unsigned int	i;

	map->data = malloc(sizeof(unsigned char *) * map->y_size);
	if (!map)
		return (false);
	i = 0;
	while (i < map->x_size)
	{
		map->data[i] = malloc(sizeof(unsigned char *) * map->x_size);
		if (map->data[i] == NULL)
		{
			while (i-- > 0)
				free(map->data[i]);
			free(map->data);
			return (false);
		}
		++i;
	}
	return (true);
}

bool	read_map(int fd, t_map *map)
{
	char	*line;
	t_list	*line_list;

	line_list = NULL;
	if (!read_map_as_list(fd, &line_list))
	{
		print_error();
		return (false);
	}
	if (!compute_map_size(line_list, map))
		return (false);
	if (!alloc_map(map))
	{
		print_error(strerror(errno));
		return (false);
	}
	if (!convert_list_to_array(line_list, map))
	{
		print_error();
		return (false);
	}
	return (true);
}
