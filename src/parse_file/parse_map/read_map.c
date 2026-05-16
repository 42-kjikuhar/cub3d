/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:38:03 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/16 18:38:11 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	read_map(int fd, t_map *map)
{
	char	*line;
	t_list	*line_list;

	line_list = NULL;
	if (!read_map_as_list(fd, line_list))
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
