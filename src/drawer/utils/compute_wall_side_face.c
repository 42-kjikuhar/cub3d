/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_wall_side_face.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 19:45:54 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 02:45:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../drawer_private.h"

static t_img	*select_texture(t_mlx *mlx, t_hit const *hit);
static double	calc_texture_u(const t_hit *hit);

t_wall_side_face	compute_wall_side_face(\
	t_mlx *mlx, t_hit const *hit)
{
	t_wall_side_face	side;
	double				texture_u;
	t_dvec3				to_point;

	side.texture = select_texture(mlx, hit);
	texture_u = calc_texture_u(hit);
	side.texture_pixel.x = (int)(side.texture->width * texture_u);
	if (texture_u == 1.0)
		side.texture_pixel.x -= 1;
	to_point = dvec3_sub(hit->front_pos, camera()->pos);
	compute_wall_point(to_point, &(side.top_depth), &(side.top));
	to_point = dvec3_sub(dvec3(hit->front_pos.x, hit->front_pos.y, 0.0), camera()->pos);
	compute_wall_point(to_point, &(side.bottom_depth), &(side.bottom));
	side.size = side.bottom - side.top + 1;
	side.draw_start = side.top;
	if (side.draw_start < 0)
		side.draw_start = 0;
	side.draw_end = side.bottom;
	if (side.draw_end >= W_HEIGHT)
		side.draw_end = W_HEIGHT - 1;
	return (side);
}

static t_img	*select_texture(t_mlx *mlx, t_hit const *hit)
{
	if (hit->hit_side == NORTH_SIDE)
		return (&(mlx->assets.north_wall));
	else if (hit->hit_side == SOUTH_SIDE)
		return (&(mlx->assets.south_wall));
	else if (hit->hit_side == WEST_SIDE)
		return (&(mlx->assets.west_wall));
	else
		return (&(mlx->assets.east_wall));
}

static double	calc_texture_u(t_hit const *hit)
{
	if (hit->hit_side == NORTH_SIDE)
		return (1.0 - (hit->front_pos.x - floor(hit->front_pos.x)));
	else if (hit->hit_side == SOUTH_SIDE)
		return (hit->front_pos.x - floor(hit->front_pos.x));
	else if (hit->hit_side == WEST_SIDE)
		return (hit->front_pos.y - floor(hit->front_pos.y));
	else
		return (1.0 - (hit->front_pos.y - floor(hit->front_pos.y)));
}
