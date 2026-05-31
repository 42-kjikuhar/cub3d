/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:37:35 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/31 23:57:36 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	parse_map_cell(int x, int y);
static bool	is_map_character(int x, int y);
static bool	is_player_cell(int x, int y);
static bool	is_surrounded_floor_cell(int x, int y);

bool	parse_map_data(void)
{
	int	x;
	int	y;

	y = 0;
	while (y < get_map_size(Y_AXIS))
	{
		x = 0;
		while (x < get_map_size(X_AXIS))
		{
			if (!parse_map_cell(x, y))
				return (false);
			++x;
		}
		++y;
	}
	if (!(get_map_player()->is_set))
	{
		print_error(ERROR_MAP_NO_PLAYER);
		return (false);
	}
	return (true);
}

static bool	parse_map_cell(int x, int y)
{
	if (!is_map_character(x, y))
	{
		print_error(ERROR_MAP_INVALID_CHAR);
		return (false);
	}
	if (is_player_cell(x, y))
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

static bool	is_map_character(int x, int y)
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

static bool	is_player_cell(int x, int y)
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
	if (is_map_outside(x, y - 1) || get_map_data(x, y - 1) == MAP_BLANK \
		|| is_map_outside(x, y + 1) || get_map_data(x, y + 1) == MAP_BLANK \
		|| is_map_outside(x - 1, y) || get_map_data(x - 1, y) == MAP_BLANK \
		|| is_map_outside(x + 1, y) || get_map_data(x + 1, y) == MAP_BLANK)
	{
		print_error(ERROR_MAP_NOT_CLOSED);
		return (false);
	}
	return (true);
}
