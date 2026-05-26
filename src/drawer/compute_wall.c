/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:08:17 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/26 17:01:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "drawer_private.h"

static t_img	*select_texture(t_mlx const *mlx, t_hit const *hit);
double		calc_texture_u(\
	const t_cub3d *cub3d, t_dvec2 ray, const t_hit *hit);

t_wall	compute_wall(const t_cub3d *cub3d, t_ray const *ray, t_hit const *hit)
{
	t_wall	wall;
	double	texture_u;

	wall.texture = select_texture(&(cub3d->mlx), hit);
	texture_u = calc_texture_u(cub3d, ray, hit);
	wall.texture_pixel.x = (int)(wall.texture->width * texture_u);
	if (texture_u == 1.0)
		wall.texture_pixel.x -= 1;
	wall.height = (int)(W_HEIGHT / hit->perp_wall_dist);
	wall.top = (W_HEIGHT - wall.height) / 2;
	wall.draw_start = wall.top;
	if (wall.draw_start < 0)
		wall.draw_start = 0;
	wall.bottom = wall.top + wall.height - 1;
	wall.draw_end = wall.bottom;
	if (wall.draw_end >= W_HEIGHT)
		wall.draw_end = W_HEIGHT - 1;
	return (wall);
}

static t_img	*select_texture(t_mlx const *mlx, t_hit const *hit)
{
	if (hit->hit_side & NORTH_SIDE)
		return (&(mlx->assets.north_wall));
	else if (hit->hit_side & SOUTH_SIDE)
		return (&(mlx->assets.south_wall));
	else if (hit->hit_side & WEST_SIDE)
		return (&(mlx->assets.west_wall));
	else
		return (&(mlx->assets.east_wall));
}

double	calc_texture_u(t_hit const *hit)
{
	if (hit->hit_side & NORTH_SIDE)
		return (1.0 - (hit->pos_x - floor(hit->pos_x)));
	else if (hit->hit_side & SOUTH_SIDE)
		return (hit->pos_x - floor(hit->pos_x));
	else if (hit->hit_side & WEST_SIDE)
		return (hit->pos_y - floor(hit->pos_y));
	else
		return (1.0 - (hit->pos_y - floor(hit->pos_y)));
}
