/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:38:03 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/16 20:37:09 by kjikuhar         ###   ########.fr       */
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
	{
		print_error();
		return (false);
	}
	if (!alloc_map(map))
	{
		print_
	}
	if (!convert_list_to_array(line_list, map))
	{
		print_error();
		return (false);
	}
	return (true);
}
