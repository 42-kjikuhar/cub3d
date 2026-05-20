/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_cell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 23:35:02 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/21 01:23:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_map_char(t_map *map, int x, int y)
{
	char	cell;

	cell = map->data[y][x];
	return (cell == MAP_FLOOR \
	|| cell == MAP_WALL \
	|| cell == MAP_BLANK \
	|| cell == PLAYER_NORTH \
	|| cell == PLAYER_SOUTH \
	|| cell == PLAYER_WEST \
	|| cell == PLAYER_EAST);
}

static bool	is_player_char(t_map *map, int x, int y)
{
	char	cell;

	cell = map->data[y][x];
	return (cell == PLAYER_NORTH \
	|| cell == PLAYER_SOUTH \
	|| cell == PLAYER_WEST \
	|| cell == PLAYER_EAST);
}

static bool	is_blank_cell(t_map *map, int x, int y)
{
	if ((y < 0 || map->y_size <= y) \
	|| (x < 0 || map->x_size <= x))
	{
		return (true);
	}
	return (map->data[y][x] == MAP_BLANK);
}

static bool	is_surrounded_floor_cell(t_map *map, int x, int y)
{
	if (is_blank_cell(map, x, y - 1) \
	|| is_blank_cell(map, x, y + 1) \
	|| is_blank_cell(map, x - 1, y) \
	|| is_blank_cell(map, x + 1, y))
	{
		print_error(ERROR_MAP_NOT_CLOSED);
		return (false);
	}
	return (true);
}

bool	parse_map_cell(t_map *map, int x, int y)
{
	if (!is_map_char(map, x, y))
		return (false);
	if (is_player_char(map, x, y))
	{
		if (map->player_dir != '\0')
		{
			print_error(ERROR_MAP_MULTI_PLAYER);
			return (false);
		}
		map->player_dir = map->data[y][x];
		map->player_pos = (t_ivec2){x, y};
	}
	if (map->data[y][x] == MAP_FLOOR \
		&& !is_surrounded_floor_cell(map, x, y))
	{
		return (false);
	}
	return (true);
}
