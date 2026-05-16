/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:37:35 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/16 22:51:43 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define	MAP_FLOOR '0'
#define	MAP_WALL '1'
#define	MAP_BLANK ' '
#define	PLAYER_NORTH 'N'
#define	PLAYER_SOUTH 'S'
#define	PLAYER_WEST 'W'
#define	PLAYER_EAST 'E'

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
	if ((y < 0 || map->y_size <= y)
	|| (x < 0 || map->x_size <= x))
	{
		return (true);
	}
	return (map->data[y][x] == MAP_BLANK);
}

static is_surrounded_floor_cell(t_map *map, int x, int y)
{
	if (is_blank_cell(map, x, y - 1) \
	|| is_blank_cell(map, x, y + 1) \
	|| is_blank_cell(map, x - 1, y) \
	|| is_blank_cell(map, x + 1, y))
	{
		print_error("ka be nu ke si te te ku sa");
		return (false);
	}
	return (true);
}

static bool	parse_map_cell(t_map *map, int x, int y)
{
	if (!is_map_char(map, x, y))
		return (false);
	if (is_player_char(map, x, y))
	{
		if (map->player_dir != '\0')
		{
			print_error("player_cell exists more two");
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
