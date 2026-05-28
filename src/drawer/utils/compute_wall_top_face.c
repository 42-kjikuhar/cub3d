/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_wall_top_face.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 19:45:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/27 22:05:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../drawer_private.h"

t_wall_top_face	compute_wall_top_face(t_player const *player, \
	t_ray const *ray, t_wall_side_face *side)
{
	t_wall_top_face	top;
	t_dvec3			back_point;
	t_dvec3			to_point;

	top.color = ((50 << 16) | (50 << 8) | (50));
	top.front_depth = side->top_depth;
	top.front = side->top;
	if (ray->wall_dist_x < ray->wall_dist_y)
	{
		if (ray->vector.x > 0)
			back_point.x = ray->cell.x + ray->cell_step.x;
		else
			back_point.x = ray->cell.x + ray->cell_step.x + 1;
		back_point.y = ray->origin.y \
						+ ray->wall_dist_x / ray->length * ray->vector.y;
	}
	else
	{
		back_point.x = ray->origin.x \
						+ ray->wall_dist_y / ray->length * ray->vector.x;
		if (ray->vector.y > 0)
			back_point.y = ray->cell.y + ray->cell_step.y;
		else
			back_point.y = ray->cell.y + ray->cell_step.y + 1;
	}
	back_point.z = WALL_HEIGHT;
	to_point = dvec3_sub(back_point, ray->origin);
	compute_wall_point(player, to_point, &(top.back_depth), &(top.back));
	top.size = top.front - top.back + 1;
	top.draw_start = top.back;
	if (top.draw_start < 0)
		top.draw_start = 0;
	top.draw_end = top.front;
	if (top.draw_end >= W_HEIGHT)
		top.draw_end = W_HEIGHT - 1;
	return (top);
}
