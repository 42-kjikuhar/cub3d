/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:14:02 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/26 22:38:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../drawer_private.h"

static void		set_cell_step(t_ray *ray);
static void		set_initial_wall_distance(t_ray *ray);

t_ray	init_ray(t_player const *player, int win_x)
{
	t_ray			ray;
	double const	t = (((double)win_x / W_WIDTH) - 0.5) * 2.0;

	ray.origin = player->pos;
	ray.vector = dvec3_add(player->dir, \
					dvec3_scale(t * player->screen_half_width, player->right));
	ray.length \
		= sqrt(ray.vector.x * ray.vector.x + ray.vector.y * ray.vector.y);
	ray.delta_dist_x = fabs(ray.length / ray.vector.x);
	ray.delta_dist_y = fabs(ray.length / ray.vector.y);
	ray.cell.x = (int)(ray.origin.x);
	ray.cell.y = (int)(ray.origin.y);
	set_cell_step(&ray);
	ray.delta_height_x = ray.delta_dist_x * tan(ray.vector.z);
	ray.delta_height_y = ray.delta_dist_y * tan(ray.vector.z);
	set_initial_wall_distance(&ray);
	return (ray);
}

static void	set_cell_step(t_ray *ray)
{
	if (ray->vector.x > 0)
		ray->cell_step.x = 1;
	else
		ray->cell_step.x = -1;
	if (ray->vector.y > 0)
		ray->cell_step.y = 1;
	else
		ray->cell_step.y = -1;
}

static void	set_initial_wall_distance(t_ray *ray)
{
	if (ray->vector.x > 0)
	{
		ray->wall_dist_x \
			= (1.0 - (ray->origin.x - floor(ray->origin.x))) * ray->delta_dist_x;
	}
	else
	{
		ray->wall_dist_x \
			= (ray->origin.x - floor(ray->origin.x)) * ray->delta_dist_x;
	}
	if (ray->vector.y > 0)
	{
		ray->wall_dist_y \
			= (1.0 - (ray->origin.y - floor(ray->origin.y))) * ray->delta_dist_y;
	}
	else
	{
		ray->wall_dist_y \
			= (ray->origin.y - floor(ray->origin.y)) * ray->delta_dist_y;
	}
}
