/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_drawer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 22:52:46 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/26 16:42:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./drawer_private.h"

static t_ray	init_ray(t_cub3d *cub3d, int win_x);
static void		set_cell_step(t_ray *ray);
static void		set_initial_wall_distance(t_ray *ray);

void	wall_drawer(t_cub3d *cub3d)
{
	int		win_x;
	t_ray	ray;
	t_hit	hit;
	t_wall	wall;

	win_x = 0;
	while (win_x < W_WIDTH)
	{
		ray = init_ray(&(cub3d->player), win_x);
		while (true)
		{
			hit = dda_algorithm(&(cub3d->map), &ray);
			if (hit.hit_side == NO_HIT)
				break ;
			wall = compute_wall(cub3d, ray, &hit);
			draw_wall(cub3d, win_x, &wall);
		}
		++win_x;
	}
}

static t_ray	init_ray(t_player const *player, int win_x)
{
	t_ray			ray;
	double const	signed_normalized_win_x \
						= (((double)win_x / W_WIDTH) - 0.5) * 2.0;

	ray.origin = player->pos;
	ray.vector = dvec3_add(player->dir, \
					dvec3_scale(signed_normalized_win_x, player->plane));
	ray.length \
		= sqrt(ray.vector.x * ray.vector.x + ray.vector.y * ray.vector.y);
	ray.delta_dist_x = fabs(ray.length / ray.vector.x);
	ray.delta_dist_y = fabs(ray.length / ray.vector.y);
	ray.cell.x = (int)(ray->origin.x);
	ray.cell.y = (int)(ray->origin.y);
	set_cell_step(&ray);
	ray.delta_height_x = ray.delta_dist_x * tan(ray.vector.z);
	ray.delta_height_y = ray.delta_dist_y * tan(ray.vector.z);
	set_initial_wall_distance(&ray);
	return (ray);
}

static void	set_cell_step(t_ray *ray)
{
	if (ray->vector.x > 0)
		ray->step.x = 1;
	else
		ray->step.x = -1;
	if (ray->vector.y > 0)
		ray->step.y = 1;
	else
		ray->step.y = -1;
}

static void	set_initial_wall_distance(t_ray *ray)
{
	if (ray->vector.x > 0)
	{
		ray->wall_dist_x \
			= (1.0 - (ray->origin.x - floor(ray->origin.x))) * ray->delta_dist.x;
	}
	else
	{
		ray->wall_dist_x \
			= (ray->origin.x - floor(ray->origin.x)) * ray->delta_dist.x;
	}
	if (ray->vector.y > 0)
	{
		ray->wall_dist_y \
			= (1.0 - (ray->origin.y - floor(ray->origin.y))) * ray->delta_dist.y;
	}
	else
	{
		ray->wall_dist_y \
			= (ray->origin.y - floor(ray->origin.y)) * ray->delta_dist.y;
	}
}
