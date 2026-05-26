/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:08:17 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/26 22:59:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "drawer_private.h"

static t_img	*select_texture(t_mlx *mlx, t_hit const *hit);
static double	calc_texture_u(const t_hit *hit);
static int		calc_screen_height(\
	t_player const *player, t_ray const *ray, t_dvec3 object_pos);

t_wall	compute_wall(t_mlx *mlx, t_player const *player, \
	t_ray const *ray, t_hit const *hit)
{
	t_wall	wall;
	double	texture_u;

	wall.texture = select_texture(mlx, hit);
	texture_u = calc_texture_u(hit);
	wall.texture_pixel.x = (int)(wall.texture->width * texture_u);
	if (texture_u == 1.0)
		wall.texture_pixel.x -= 1;
	wall.top = calc_screen_height(player, ray, \
					dvec3(hit->pos_x, hit->pos_y, WALL_HEIGHT));
	wall.bottom = calc_screen_height(player, ray, \
					dvec3(hit->pos_x, hit->pos_y, 0));
	wall.height = wall.bottom - wall.top + 1;
	wall.draw_start = wall.top;
	if (wall.draw_start < 0)
		wall.draw_start = 0;
	wall.bottom = wall.top + wall.height - 1;
	wall.draw_end = wall.bottom;
	if (wall.draw_end >= W_HEIGHT)
		wall.draw_end = W_HEIGHT - 1;
	return (wall);
}

static t_img	*select_texture(t_mlx *mlx, t_hit const *hit)
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

static double	calc_texture_u(t_hit const *hit)
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

// intのオーバーフローを考慮できていない。
static int	calc_screen_height(\
	t_player const *player, t_ray const *ray, t_dvec3 object_pos)
{
	t_dvec3	to_object;
	double	depth;
	double	v;

	to_object = dvec3_sub(object_pos, ray->origin);
	depth = dvec3_dot(player->dir, to_object);
	v = dvec3_dot(to_object, player->up) / (player->screen_half_height * depth);
	return ((int)round(((1.0 - v) / 2.0) * W_HEIGHT));
}
