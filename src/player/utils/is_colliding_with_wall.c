/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_colliding_with_wall.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 00:28:15 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/27 07:58:49 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_dvec3	calc_cells_to_check(t_dvec3 pos);

bool	is_colliding_with_wall(t_map const *map, t_dvec3 pos)
{
	t_dvec3	check_pos;

	if (map->data[(int)pos.y][(int)pos.x] == MAP_WALL)
		return (true);
	check_pos = calc_cells_to_check(pos);
	if (0.0 <= check_pos.x && check_pos.x < map->x_size \
		&& map->data[(int)pos.y][(int)(check_pos.x)] == MAP_WALL)
	{
		return (true);
	}
	if (0.0 <= check_pos.y && check_pos.y < map->y_size \
		&& map->data[(int)(check_pos.y)][(int)pos.x] == MAP_WALL)
	{
		return (true);
	}
	if (0.0 <= check_pos.x && check_pos.x < map->x_size \
		&& 0.0 <= check_pos.y && check_pos.y < map->y_size \
		&& map->data[(int)(check_pos.y)][(int)(check_pos.x)] == MAP_WALL)
	{
		return (true);
	}
	return (false);
}

static t_dvec3	calc_cells_to_check(t_dvec3 pos)
{
	t_dvec3	check_pos;

	check_pos = dvec3(pos.x, pos.y, 0);
	if (pos.x - floor(pos.x) <= PLAYER_OFFSET)
		check_pos.x = pos.x - PLAYER_OFFSET;
	else if (ceil(pos.x) - pos.x <= PLAYER_OFFSET)
		check_pos.x = pos.x + PLAYER_OFFSET;
	if (pos.y - floor(pos.y) <= PLAYER_OFFSET)
		check_pos.y = pos.y - PLAYER_OFFSET;
	else if (ceil(pos.y) - pos.y <= PLAYER_OFFSET)
		check_pos.y = pos.y + PLAYER_OFFSET;
	return (check_pos);
}
