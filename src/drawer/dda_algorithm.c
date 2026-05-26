/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 13:21:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/26 23:01:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "drawer_private.h"

static void	check_wall_hit(t_map const *map, t_ray *ray, t_hit *hit);

t_hit	dda_algorithm(t_map const *map, t_ray *ray)
{
	t_hit	hit;

	hit.hit_side = NO_HIT;
	while (hit.hit_side == NO_HIT)
	{
		if (ray->wall_dist_x < ray->wall_dist_y)
			ray->cell.x += ray->cell_step.x;
		else
			ray->cell.y += ray->cell_step.y;
		if (ray->cell.x < 0 || map->x_size <= ray->cell.x \
			|| ray->cell.y < 0 || map->y_size <= ray->cell.y)
		{
			break ;
		}
		check_wall_hit(map, ray, &hit);
		if (ray->wall_dist_x < ray->wall_dist_y)
			ray->wall_dist_x += ray->delta_dist_x;
		else
			ray->wall_dist_y += ray->delta_dist_y;
	}
	return (hit);
}

static void	check_wall_hit(t_map const *map, t_ray *ray, t_hit *hit)
{
	if (map->data[ray->cell.y][ray->cell.x] == MAP_WALL)
	{
		if (ray->wall_dist_x < ray->wall_dist_y)
		{
			hit->perp_wall_dist = ray->wall_dist_x / ray->length;
			if (ray->vector.x > 0)
				hit->hit_side |= WEST_SIDE;
			else
				hit->hit_side |= EAST_SIDE;
			hit->pos_x = ray->cell.x;
			hit->pos_y = ray->origin.y \
							+ ray->wall_dist_x / ray->length * ray->vector.y;
		}
		else
		{
			hit->perp_wall_dist = ray->wall_dist_y / ray->length;
			if (ray->vector.y > 0)
				hit->hit_side |= SOUTH_SIDE;
			else
				hit->hit_side |= NORTH_SIDE;
			hit->pos_x = ray->origin.x \
							+ ray->wall_dist_y / ray->length * ray->vector.x;
			hit->pos_y = ray->cell.y;
		}
	}
}
