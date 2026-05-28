/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_hitting_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 13:21:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/28 21:12:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./drawer_private.h"

static bool				is_map_outside(t_map const *map, int x, int y);
static enum e_hit_side	calc_hit_side(t_dda const *dda);
static t_dvec3			calc_hit_pos(t_dda const *dda, double wall_height);

t_hit	search_hitting_wall(t_map const *map, t_dda *dda)
{
	t_hit	hit;

	hit.hit_side = NO_HIT;
	while (hit.hit_side == NO_HIT)
	{
		if (dda->dist_x < dda->dist_y)
			dda->cell.x += dda->cell_step.x;
		else
			dda->cell.y += dda->cell_step.y;
		if (is_map_outside(map, dda->cell.x, dda->cell.y))
			return (hit);
		if (map->data[dda->cell.y][dda->cell.x] == MAP_WALL)
		{
			hit.hit_side = calc_hit_side(dda);
			hit.front_pos = calc_hit_pos(dda, WALL_HEIGHT);
		}
		if (dda->dist_x < dda->dist_y)
			dda->dist_x += dda->delta_dist_x;
		else
			dda->dist_y += dda->delta_dist_y;
	}
	hit.back_pos = calc_hit_pos(dda, WALL_HEIGHT);
	return (hit);
}

static bool	is_map_outside(t_map const *map, int x, int y)
{
	return (x < 0 || map->x_size <= x || y < 0 || map->y_size <= y);
}

static enum e_hit_side	calc_hit_side(t_dda const *dda)
{
	if (dda->dist_x < dda->dist_y)
	{
		if (dda->ray.x > 0)
			return (WEST_SIDE);
		else
			return (EAST_SIDE);
	}
	else
	{
		if (dda->ray.y > 0)
			return (SOUTH_SIDE);
		else
			return (NORTH_SIDE);
	}
}

static t_dvec3	calc_hit_pos(t_dda const *dda, double wall_height)
{
	t_dvec3	hit_pos;
	double	dist;

	if (dda->dist_x < dda->dist_y)
		dist = dda->dist_x;
	else
		dist = dda->dist_y;
	if (dda->ray.x > 0)
		hit_pos.x = dda->origin.x + (dist / dda->delta_dist_x);
	else
		hit_pos.x = dda->origin.x - (dist / dda->delta_dist_x);
	if (dda->ray.y > 0)
		hit_pos.y = dda->origin.y + (dist / dda->delta_dist_y);
	else
		hit_pos.y = dda->origin.y - (dist / dda->delta_dist_y);
	hit_pos.z = wall_height;
	return (hit_pos);
}
