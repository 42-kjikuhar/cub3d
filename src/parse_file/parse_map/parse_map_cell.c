/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_cell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 23:35:02 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/30 13:20:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_map_char(int x, int y);
static bool	is_player_char(int x, int y);
static bool	is_surrounded_floor_cell(int x, int y);
static bool	is_blank_cell(int x, int y);

bool	parse_map_cell(int x, int y)
{
	if (!is_map_char(x, y))
		return (false);
	if (is_player_char(x, y))
	{
		if (get_map_player()->is_set)
		{
			print_error(ERROR_MAP_MULTI_PLAYER);
			return (false);
		}
		set_map_player(get_map_data(x, y), ivec2(x, y));
		set_map_data(x, y, MAP_FLOOR);
	}
	if (get_map_data(x, y) == MAP_FLOOR \
		&& !is_surrounded_floor_cell(x, y))
	{
		return (false);
	}
	return (true);
}

static bool	is_map_char(int x, int y)
{
	char	cell;

	cell = get_map_data(x, y);
	return (cell == MAP_FLOOR \
			|| cell == MAP_WALL \
			|| cell == MAP_BLANK \
			|| cell == PLAYER_NORTH \
			|| cell == PLAYER_SOUTH \
			|| cell == PLAYER_WEST \
			|| cell == PLAYER_EAST);
}

static bool	is_player_char(int x, int y)
{
	char	cell;

	cell = get_map_data(x, y);
	return (cell == PLAYER_NORTH \
			|| cell == PLAYER_SOUTH \
			|| cell == PLAYER_WEST \
			|| cell == PLAYER_EAST);
}

static bool	is_surrounded_floor_cell(int x, int y)
{
	if (is_blank_cell(x, y - 1) \
		|| is_blank_cell(x, y + 1) \
		|| is_blank_cell(x - 1, y) \
		|| is_blank_cell(x + 1, y))
	{
		print_error(ERROR_MAP_NOT_CLOSED);
		return (false);
	}
	return (true);
}

static bool	is_blank_cell(int x, int y)
{
	if (is_map_outside(x, y))
		return (true);
	return (get_map_data(x, y) == MAP_BLANK);
}
