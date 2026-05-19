/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:37:35 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/17 12:46:17 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./parse_map_private.h"

bool	parse_map_data(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y_size)
	{
		x = 0;
		while (x < map->x_size)
		{
			if (!parse_map_cell(map, x, y))
				return (false);
			++x;
		}
		++y;
	}
	if (map->player_dir == '\0')
	{
		print_error("no player");
		return (false);
	}
	return (true);
}
