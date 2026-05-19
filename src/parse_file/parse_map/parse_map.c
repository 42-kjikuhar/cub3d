/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:36:09 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/19 21:52:12 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./parse_map_private.h"

bool	parse_map(int fd, t_map *map)
{
	if (!read_map(fd, map))
	{
		print_error("read_map_error");
		return (false);
	}
	if (!parse_map_data(map))
	{
		cleanup_map(map);
		return (false);
	}
	return (true);
}
